#include "clientregisterhandler.h"

#include <QDebug>

#include "Utilities/log.h"

ClientRegisterHandler::ClientRegisterHandler(QObject *parent) : MsgHandler(parent)
{
}

void ClientRegisterHandler::parse(Msg & msg){
    //不光要返回是否注册成功 还要返回账号信息
    MsgType registerStatus = msg.getType();

    if(registerStatus == MsgType::REGISTER_SUCCESS){
        emit sigRegSuccessful(UserInfo::fromQByteArray(msg.getContent()));
        Log::GetLogObj()->writeLog("[ClientRegisterHandler] 注册成功");
    }else{
        emit sigRegFailed();
        Log::GetLogObj()->writeLog("[ClientRegisterHandler] 注册失败");
    }
}
