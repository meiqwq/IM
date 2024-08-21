#include "chatmsghandler.h"

#include "Utilities/utilities.h"

ChatMsgHandler::ChatMsgHandler(QObject *parent) : MsgHandler(parent)
{

}

void ChatMsgHandler::parse(Msg & msg){
    Log::GetLogObj()->writeLog("[ClientMsgHandler] received msg");
    emit readyShowChatMsg(ChatMessage::fromQByteArray(msg.getContent()));
}
