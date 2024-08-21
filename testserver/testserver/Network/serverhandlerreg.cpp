#include "serverhandlerreg.h"

QMap<MsgType, MsgHandler * > ServerHandlerReg::handler_regs;
ServerHandlerReg * ServerHandlerReg::regObj = nullptr;

ServerHandlerReg::ServerHandlerReg(QObject * parent):
    QObject(parent)
{
    initialize();
}

ServerHandlerReg * ServerHandlerReg::GetRegObj(){
    if(!regObj){
        regObj = new ServerHandlerReg();
    }
    return regObj;
}

MsgHandler * ServerHandlerReg::getHandler(MsgType type){
    if(handler_regs.contains(type)){
        qDebug()<<"yess";
        return handler_regs[type];
    }
    qDebug()<<"noo";
    return nullptr;
}

void ServerHandlerReg::regHandler(MsgType type, MsgHandler *msg_handler){
    handler_regs[type] = msg_handler;
}

void ServerHandlerReg::initialize(){
    MsgHandler * msghandler = new ChatMsgHandler(this);
    regHandler(MsgType::MSG_PLAIN_TEXT,msghandler);

    MsgHandler * loginhandler = new LoginHandler(this);
    regHandler(MsgType::REQUEST_LOGIN, loginhandler );

    MsgHandler * reghandler = new RegisterHandler(this);
    regHandler(MsgType::REQUEST_REGISTER, reghandler);
}
