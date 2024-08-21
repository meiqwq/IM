#include "chatmsghandler.h"
#include"DataBase/datadb.h"
#include"servercontroller.h"

#include "Utilities/log.h"

ChatMsgHandler::ChatMsgHandler(QObject* parent) : MsgHandler(parent)
{

}
void ChatMsgHandler::parse(Msg& msg, TcpClientSocket* socket) {
    Log::GetLogObj()->writeLog("[ChatMsgHandler] Trying Parse");
    if (msg.getType() != MsgType::MSG_PLAIN_TEXT) {
        Log::GetLogObj()->writeLog("[ChatMsgHandler] Chat Msg error!");
        return;
    }
    ChatMessage chatmsg = ChatMessage::fromQByteArray(msg.getContent());
    Log::GetLogObj()->writeLog("[ChatMsgHandler] 正在转发消息: {" + QString::number(chatmsg.getSender())+", "
                               + QString::number(chatmsg.getReceiver())+", "
                               + chatmsg.getTimeStamp() + ", "
                               + chatmsg.getContent() + "}");
    DataDB* db = DataDB::GetInstance();
    db->addMsg(chatmsg.getSender(), chatmsg.getReceiver(), chatmsg.getContent(), chatmsg.getTimeStamp());
    Server* s = ServerController::getServerInstance();
    s->getClients(chatmsg.getReceiver())->sendMessage(&msg);
    Log::GetLogObj()->writeLog("[ChatMsgHandler] Parse Successful.");
}

