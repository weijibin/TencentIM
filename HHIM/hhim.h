#ifndef HHIM_H
#define HHIM_H

#include "hhim_global.h"
#include <QObject>
#include "callback.h"
#include "tim_c.h"
#include "tim_group_c.h"

class QNetworkAccessManager;
class HHIMSHARED_EXPORT HHIM : public QObject
{
    Q_OBJECT

public:
    static HHIM* getInstance();

    void login(int app_id,QString user_id,int accoutType,QString user_sig);
    void logout();

    void joinGroup(QString id);
    void quitGroup(QString id);
    void queryGroupMemberList(QString id);

    void sendC2CMsg(QString id ,QString msg);  // 发送消息
    void sendC2GMsg(QString id ,QString msg);

signals:
    void sigRecMsg(const QString &info);           // 接收消息
    void sigJoinGroup(const QString &groupId,const QStringList &ids);
    void sigQuitGroup(const QString &groupId,const QStringList &ids);
    void sigKickOffline();
    void sigErrorCode(const QString &info);  // 请求出错
    void sigMemberList(const QStringList &memberList); // 群成员列表

private:

    void hhLogin(int app_id,TIMUserInfo *user, QString user_sig);  //登录
    void hhLogout();                                                                            //登出

    void initIM();
    void uninitIM();

    void initCallBack();

    void setMessageCallBack();   // 消息回调
    void setConnCallBack();         // 断网 联网 回调
    void setGroupCallBack();        // 群组状态消息 回调(非消息回调)
    void setKickOfflineCallBack(); // 互踢回调

public:
    HHIM();
    ~HHIM();
};

#endif // HHIM_H
