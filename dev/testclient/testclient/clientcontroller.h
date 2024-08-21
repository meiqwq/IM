#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H

#include <QObject>

#include "DataModel/chatmessage.h"
#include "Network/handlerconnect.h"
#include "Network/tcpclientsocket.h"

class ClientController : public QObject
{
    Q_OBJECT
public:
    explicit ClientController(QObject *parent = nullptr);

    //客户端初始化函数,是调用这个类的函数之前必须调用且仅调用一次的入口.
    static void clientInitialize();

    //发送消息的函数
    static void SendChatMessage(ChatMessage & chat_msg);
    static void SendChatMessage(quint32 receiver, QString content);

    //发送登录 注册的请求 它们都会调用SafeUtilites::GetPasswordHash(password)去加密明文密码
    static void SendLoginRequest(quint32 id, QString password);
    static void SendRegisterRequest(QString username, QString password);

    //获取本地的聊天记录
	static void InitChatMsgList(quint32 id);
    static QList<ChatMessage> GetChatMsgList(quint32 id);

    static UserInfo GetMyInfo();

    friend class ClientMessageHandler;
signals:

private:
    //ClientController负责托管Socket
    static void ConnectToServer();
    static TcpClientSocket * GetSocket();
    static TcpClientSocket * socket;
    static QMap<quint32, QList<ChatMessage>> chatmsgmap;
};

#endif // CLIENTCONTROLLER_H
