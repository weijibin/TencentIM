#include "hhim.h"
#include "tim_c.h"
#include "tim_group_assistant.h"
#include <QString>
#include <QNetworkAccessManager>
#include <QThread>

HHIM *HHIM::getInstance()
{
    static HHIM instance;
    return &instance;
}

HHIM::HHIM()
{
    initIM();
}

HHIM::~HHIM()
{
    uninitIM();
}

void HHIM::initIM()
{
    TIMSetMode(1); //IM 模式
    TIMInit();
}
void HHIM::uninitIM()
{
    TIMUninit();
}

void HHIM::login(int app_id,QString user_id,int accoutType,QString user_sig)
{
    QByteArray ba = QString::number(app_id).toLatin1();
    char* appID = ba.data();

    char type[20];
    _itoa(accoutType,type,10);

    QByteArray ba1 = user_id.toLatin1();
    char* userID = ba1.data();

    TIMUserInfo user;
    user.account_type = type;
    user.app_id_at_3rd = appID;
    user.identifier = userID;

    QString sig = user_sig;
    hhLogin(app_id,&user,sig);
}

void HHIM::logout()
{
    hhLogout();
}

void HHIM::hhLogin(int app_id,TIMUserInfo *user, QString user_sig)
{
    int sdk_app_id = app_id;

    QByteArray ba = user_sig.toLatin1();
    const char* sig = ba.data();

    char info[] = "login";

    static TIMCommCB callback;
    callback.OnSuccess = CommonCallBack::CBCommOnSuccess;
    callback.OnError = CommonCallBack::CBCommOnError;
    callback.data = info;
    TIMLogin(sdk_app_id, user, sig, &callback);
}
void HHIM::hhLogout()
{
    const char *info = "logout";
    static TIMCommCB callback;
    callback.OnSuccess = CommonCallBack::CBCommOnSuccess;
    callback.OnError = CommonCallBack::CBCommOnError;
//    callback.data = info;
    TIMLogout(&callback);
}

void HHIM::joinGroup(QString id)
{
    static TIMCommCB callback;
    callback.OnSuccess = CommonCallBack::CBCommOnSuccess;
    callback.OnError = CommonCallBack::CBCommOnError;
//    callback.data = info;
    const char * hello_msg = "hello";
    QByteArray ba = id.toLatin1();
    const char*groupid = ba.data();
    TIMApplyJoinGroup( groupid,hello_msg, &callback);
}
void HHIM::quitGroup(QString id)
{
    static TIMCommCB callback;
    callback.OnSuccess = CommonCallBack::CBCommOnSuccess;
    callback.OnError = CommonCallBack::CBCommOnError;
//    callback.data = info;
//    const char * hello_msg = "hello";
    QByteArray ba = id.toLatin1();
    const char*groupid = ba.data();

    TIMQuitGroup(groupid, &callback);
}

void HHIM::sendC2CMsg(QString id ,QString data)
{
    QByteArray ba = id.toLatin1();
    const char*peer = ba.data();

    TIMConversationHandle conv = CreateConversation();
    int rt = TIMGetConversation(conv, kCnvC2C, peer);
    TIMMsgElemHandle msg = CreateTIMMessage();
    TIMMsgCustomElemHandle elem = CreateCustomElemHandle();

    FILE* file = fopen("custom.data", "rb");
    fseek(file, 0, SEEK_END);
    uint32_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    void* buf = malloc(file_size);
    fread(buf, 1, file_size, file);
    fclose(file);

    SetCustomElemData(elem, (const char*)buf, file_size);
    AddElem(msg, elem);
    TIMCommCB callback;
    callback.OnSuccess = CommonCallBack::CBCommOnSuccess;
    callback.OnError = CommonCallBack::CBCommOnError;
    SendMsg(conv, msg, &callback);
//    SLEEP(1);
    free(buf);
    DestroyConversation(conv);
    DestroyTIMMessage(msg);
    DestroyElem(elem);
}

void HHIM::sendC2GMsg(QString id ,QString data)
{
    QByteArray ba = id.toLatin1();
    const char*peer = ba.data();

    TIMConversationHandle conv = CreateConversation();
    int rt = TIMGetConversation(conv, kCnvGroup, peer);

    TIMMessageHandle msg = CreateTIMMessage();
    TIMMsgTextElemHandle elem = CreateMsgTextElem();

    QByteArray da1 = data.toLocal8Bit();
    char * content = da1.data();

    SetContent(elem, content);

    AddElem(msg, elem);
    TIMCommCB callback;
    callback.OnSuccess = CommonCallBack::CBCommOnSuccess;
    callback.OnError = CommonCallBack::CBCommOnError;
    SendMsg(conv, msg, &callback);
//    //....wait for callback
//    SLEEP(1);
    DestroyConversation(conv);
    DestroyTIMMessage(msg);
    DestroyElem(elem);
}

void HHIM::initCallBack()
{
    setMessageCallBack();
    setConnCallBack();
    setGroupCallBack();
    setKickOfflineCallBack();
}

void HHIM::setMessageCallBack()
{
    static TIMMessageCB callback;
    callback.OnNewMessage = MessageCallBack::OnNewMessage;
    TIMSetMessageCallBack(&callback);
}

void HHIM::setConnCallBack()
{
    static TIMConnCB callback;
    callback.OnConnected = ConnCallBack::OnConnected;
    callback.OnDisconnected = ConnCallBack::OnDisconnected;
    callback.data = &callback;
    TIMSetConnCallBack(&callback);
}

void HHIM::setGroupCallBack()
{
    TIMEnableGroupAssistantStorage();
    static TIMGroupAssistantCallBack callback;
    callback.onMemberJoin = GroupNotifyCallBack::MemberJoin;
    callback.onMemberQuit = GroupNotifyCallBack::MemberQuit;
    callback.onMemberUpdate = GroupNotifyCallBack::MemberUpdate;
    callback.onAdd = GroupNotifyCallBack::GroupAdd;
    callback.onQuit = GroupNotifyCallBack::GroupDelete;
    callback.onUpdate = GroupNotifyCallBack::GroupUpdate;
    TIMSetGroupAssistantCallBack(&callback);
}

void HHIM::setKickOfflineCallBack()
{
    static TIMForceOfflineCB callback;
    callback.OnKickOffline = ForceOfflineCallBack::OnForceOffline;
    callback.data = &callback;
    TIMSetKickOfflineCallBack(&callback);
}

void HHIM::queryGroupMemberList(QString id)
{
    QByteArray ba = id.toLatin1();
    const char*groupid = ba.data();

    TIMGetGroupMemberInfoCB callback;
    callback.OnSuccess = GroupMemberListCallBack::GetGroupMemberInfoOnSuccess;
    callback.OnError = GroupMemberListCallBack::GetGroupMemberInfoOnError;
    TIMGetGroupMembers(groupid, &callback);
//    //wait for callback
//    SLEEP(1);
 }
void CBGetGroupMemberInfoOnSuccessImp(TIMGroupMemberInfoHandle* handle_array, uint32_t array_size, void* data)
{

}

