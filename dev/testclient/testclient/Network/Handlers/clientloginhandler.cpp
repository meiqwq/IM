#include "clientloginhandler.h"

#include <QDebug>

#include "Utilities/log.h"

ClientLoginHandler::ClientLoginHandler(QObject *parent) : MsgHandler(parent)
{
}

void ClientLoginHandler::parse(Msg & msg){
    MsgType loginStatus = msg.getType();

    if(loginStatus == MsgType::LOGIN_SUCCESS){
        myInfo = UserInfo::fromQByteArray(msg.getContent());
        emit sigLoginSuccessful(myInfo);
        Log::GetLogObj()->writeLog("[ClientLoginHandler] 登录成功");
    }else{
        emit sigLoginFailed();
        Log::GetLogObj()->writeLog("[ClientLoginHandler] 登录失败");
    }
}

UserInfo ClientLoginHandler::getMyInfo(){
    return myInfo;
}
