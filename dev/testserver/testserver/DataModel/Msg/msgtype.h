#ifndef MSGTYPE_H
#define MSGTYPE_H

#include <QObject>

//消息的类型
enum class MsgType : quint16{

    UNDEFINED = 0x0000,//未定义的通讯类型

    //客户端处理的消息
    MSG_PLAIN_TEXT = 0x0001, MSG_PIC, MSG_EMOTION, MSG_FILE, MSG_AUDIO, MSG_VIDEO,

    //登录部分客户端向服务器发起的请求
    //注册和登录请求 重置密码请求
    REQUEST_REGISTER = 0x0020, REQUEST_LOGIN, REQUEST_RESETPW,
    //服务器向客户端返回的内容
    LOGIN_SUCCESS = 0x0030, LOGIN_ERROR, //登录成功/失败
    REGISTER_SUCCESS, REGISTER_ERROR, //注册成功/失败
    RESETPW_SUCCESS, RESETPW_ERROR, //重置密码成功/失败

    //好友管理请求 加人/加群
    REQUEST_ADD_FRIEND = 0x0050, REQUEST_JOIN_GROUP,

    //接受 拒绝 忽略
    REQUEST_AGREED, REQUEST_DECLINED, REQUEST_IGNORED,

    //好友信息
    ONLINE_FRIEND_LIST, REQUEST_FRIEND_INFO,

    //在线/离线状态转换
    STATUS_ONLINE,  STATUS_OFFLINE
};


#endif // MSGTYPE_H
