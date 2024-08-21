#include "clientcontroller.h"

#include "DataModel/Msg/msg.h"
#include "Utilities/utilities.h"


void ClientController::SendChatMessage(quint32 receiver, QString content){
    ChatMessage chat_msg(GetMyInfo().getID(), receiver, content);
    SendChatMessage(chat_msg);
}

void ClientController::SendChatMessage(ChatMessage & chat_msg){
    Log::GetLogObj()->writeLog("[正在发送] "+chat_msg.getContent());
    GetSocket()->sendMessage(
                    new Msg(MsgType::MSG_PLAIN_TEXT, chat_msg.toQByteArray())
                );
}
