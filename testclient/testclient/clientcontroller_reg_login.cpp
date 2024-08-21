#include "clientcontroller.h"
#include "Utilities/safeutilities.h"
#include "Network/handlerreg.h"

UserInfo ClientController::GetMyInfo(){
    ClientLoginHandler * tmp = (ClientLoginHandler *) HandlerReg::GetRegObj()->getHandler(MsgType::LOGIN_SUCCESS);
    return tmp->getMyInfo();
}

void ClientController::SendLoginRequest(quint32 id, QString password){

    password = SafeUtilities::GetPasswordHash(password);
    //密码做一次哈希

    UserInfo tmp(id, "", password);

    ConnectToServer();

    GetSocket()->sendMessage(new Msg(MsgType::REQUEST_LOGIN,tmp.toQByteArray()));
}

void ClientController::SendRegisterRequest(QString username, QString password){

    password = SafeUtilities::GetPasswordHash(password);
    //密码做一次哈希

    UserInfo tmp = UserInfo(0x0000, username, password);

    ConnectToServer();

    GetSocket()->sendMessage(new Msg(MsgType::REQUEST_REGISTER,tmp.toQByteArray()));
}

