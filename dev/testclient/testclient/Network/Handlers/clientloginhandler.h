#ifndef CLIENTLOGINHANDLER_H
#define CLIENTLOGINHANDLER_H

#include <QObject>

#include "msghandler.h"

class ClientLoginHandler : public MsgHandler
{
    Q_OBJECT
public:
    explicit ClientLoginHandler(QObject *parent = nullptr);

    void parse(Msg & );

    UserInfo getMyInfo();

signals:
    void sigLoginFailed();
    void sigLoginSuccessful(UserInfo info);

private:
    UserInfo myInfo;
};

#endif // CLIENTLOGINHANDLER_H
