#include "callback.h"
#include "../HHIM/hhim.h"
#include <QDebug>

void ConnCallBack::OnConnected(void* data)
{
    qDebug()<<"OnConnect! callback:%x"<<data;
}
void ConnCallBack::OnDisconnected(void* data)
{
    qDebug()<<"OnDisconnect! callback:%x"<<data;
}

void ForceOfflineCallBack::OnForceOffline(void* data)
{
    qDebug()<<"ForceOffline! callback:%x"<<data;
    emit HHIM::getInstance()->sigKickOffline();
}

void MessageCallBack::OnNewMessage(TIMMessageHandle* handles, uint32_t msg_num, void* data)
{
    // 接收消息
    const uint32_t MAX_TXT_LEN = 100;
    static int msg_count = 0;
    static char buffer[MAX_TXT_LEN] = {};
    for (int msg_idx = 0; msg_idx < msg_num; msg_idx++)
    {
        printf("new message %d\n", msg_count++);
        TIMMessageHandle handle = handles[msg_idx];
        TIMConversationHandle conv = CreateConversation();
        GetConversationFromMsg(conv, handle);
        for (int i = 0; i < GetElemCount(handle); i++)
        {
            auto elem = GetElem(handle, i);
            auto type = GetElemType(elem);
            printf("type = <%d>\n", type);
            if (type == kElemText)
            {
                auto len = MAX_TXT_LEN;
                GetContent(elem, buffer, &len);
                printf("text msg:%s", buffer);
                emit HHIM::getInstance()->sigRecMsg(QString(buffer));
            }
        }
        DestroyConversation(conv);
    }
}

void GroupNotifyCallBack::MemberJoin(const char *groupId, const char **id, uint32_t num)
{
    qDebug()<<"MemberJoin! callback:%x"<<groupId<<num<<"=="<<QString(*id);

    QString group(groupId);
    QStringList ids;
    for(int i =0; i<num; i++)
    {
        ids.append(QString(*(id+i)));
    }
    emit HHIM::getInstance()->sigJoinGroup(group,ids);
}
void GroupNotifyCallBack::MemberQuit(const char *groupId, const char **id, uint32_t num)
{
    qDebug()<<"MemberQuit! callback:%x"<<groupId<<num<<"=="<<QString(*id);

    QString group(groupId);
    QStringList ids;
    for(int i =0; i<num; i++)
    {
        ids.append(QString(*(id+i)));
    }
    emit HHIM::getInstance()->sigQuitGroup(group,ids);
}

void GroupNotifyCallBack::MemberUpdate(const char *groupId, const char **id, uint32_t num)
{
    qDebug()<<"MemberUpdate! callback:%x"<<groupId<<num<<"=="<<QString(*id);
}

void GroupNotifyCallBack::GroupAdd(const char *groupId)
{
    qDebug()<<"GroupAdd! callback:%x"<<groupId;
}

void GroupNotifyCallBack::GroupDelete(const char *groupId)
{
    qDebug()<<"GroupDelete! callback:%x"<<groupId;
}

void GroupNotifyCallBack::GroupUpdate(const char *groupId)
{
    qDebug()<<"GroupUpdate! callback:%x"<<groupId;
}

void GroupMemberListCallBack::GetGroupMemberInfoOnSuccess(TIMGroupMemberInfoHandle* handle_array, uint32_t array_size, void* data)
{
    QStringList list;
    char buf[100] = {0};
    for (uint32_t i = 0; i<array_size; i++)
    {
        uint32_t len = 100;
        GetGroupMemberID(handle_array[i], buf, &len);
        list.append(QString(buf));
    }
    emit HHIM::getInstance()->sigMemberList(list);
}

void GroupMemberListCallBack::GetGroupMemberInfoOnError(int code, const char *desc, void *data)
{
    QString err = QString("Error! code = <%1> desc = <%2>").arg(code).arg(QString(desc));
    qDebug()<<err
        <<QString(static_cast<char*>(data));
    emit HHIM::getInstance()->sigErrorCode(err);
}

void CommonCallBack::CBCommOnSuccess(void* data)
{
    qDebug()<<"Success"<<QString(static_cast<char*>(data));
}

void CommonCallBack::CBCommOnError(int code, const char* desc, void* data)
{
    QString err = QString("Error! code = <%1> desc = <%2>").arg(code).arg(QString(desc));
    qDebug()<<err
        <<QString(static_cast<char*>(data));
    emit HHIM::getInstance()->sigErrorCode(err);
}
