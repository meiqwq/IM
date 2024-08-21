#ifndef CLIENTREGISTERHANDLER_H
#define CLIENTREGISTERHANDLER_H

#include <QObject>

#include "msghandler.h"

class ClientRegisterHandler : public MsgHandler
{
    Q_OBJECT
public:
    explicit ClientRegisterHandler(QObject *parent = nullptr);

    void parse(Msg & );

signals:
    void sigRegSuccessful(UserInfo info);
    void sigRegFailed();

};

#endif // CLIENTREGISTERHANDLER_H
