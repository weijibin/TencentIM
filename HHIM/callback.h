#ifndef CALLBACK_H
#define CALLBACK_H
#include "tim_c.h"
// 网络连接
class ConnCallBack {
public:
    static void OnConnected(void* data);
    static void OnDisconnected(void* data);
};

// 互踢
class  ForceOfflineCallBack {
public:
    static void OnForceOffline(void* data);
};

// 接收消息
class MessageCallBack {
public:
    static void OnNewMessage(TIMMessageHandle* handles, uint32_t msg_num, void* data);
};

// 获取群成员
class GroupMemberListCallBack {
public:
    static void GetGroupMemberInfoOnSuccess(TIMMessageHandle* handles, uint32_t msg_num, void* data);
    static void GetGroupMemberInfoOnError(int code, const char* desc, void* data);
};

class GroupNotifyCallBack {
public:
    static void MemberJoin(const char* groupId, const char** id, uint32_t num);
    static void MemberQuit(const char* groupId, const char** id, uint32_t num);
    static void MemberUpdate(const char* groupId, const char** id, uint32_t num);
    //group info notify
    static void GroupAdd(const char* groupId);
    static void GroupDelete(const char* groupId);
    static void GroupUpdate(const char* groupId);
};

class CommonCallBack {
public:
    static void CBCommOnSuccess(void* data);
    static void CBCommOnError(int code, const char* desc, void* data);
};


#endif // CALLBACK_H
