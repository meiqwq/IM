#include "handlerreg.h"

QMap<MsgType, MsgHandler * > HandlerReg::handler_regs;
HandlerReg * HandlerReg::regObj = nullptr;

HandlerReg::HandlerReg(QObject * parent)
    :QObject(parent)
{
    initialize();
}


HandlerReg * HandlerReg::GetRegObj(){
    if(!regObj){
        regObj = new HandlerReg();
    }
    return regObj;
}

MsgHandler * HandlerReg::getHandler(MsgType type){
    if(handler_regs.contains(type)){
        return handler_regs[type];
    }
    return nullptr;
}

void HandlerReg::regHandler( MsgType type, MsgHandler * msg_handler){
    if(!handler_regs.contains(type)){
        handler_regs[type] = msg_handler;
    }else{
        handler_regs[MsgType::UNDEFINED] = msg_handler;
    }
}



void HandlerReg::initialize(){
    //指定父对象, 原则上应该不会泄漏, qt应该会回收掉才对

    MsgHandler * msghandler = new ChatMsgHandler(this);
    regHandler(MsgType::MSG_PLAIN_TEXT, msghandler );

    MsgHandler * loginhandler = new ClientLoginHandler(this);
    regHandler(MsgType::LOGIN_SUCCESS, loginhandler );
    regHandler(MsgType::LOGIN_ERROR, loginhandler );

    MsgHandler * reghandler = new ClientRegisterHandler(this);
    regHandler(MsgType::REGISTER_SUCCESS, reghandler);
    regHandler(MsgType::REGISTER_ERROR, reghandler);
}

