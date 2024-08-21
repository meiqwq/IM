#include "handlerconnect.h"

#include "handlerreg.h"

HandlerConnect::HandlerConnect(QObject *parent) : QObject(parent)
{
//CodeHere
    //connect()
    MsgHandler * h = HandlerReg::GetRegObj()->getHandler(MsgType::MSG_PLAIN_TEXT);
    //do connect
}
