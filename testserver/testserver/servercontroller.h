#ifndef SERVERCONTROLLER_H
#define SERVERCONTROLLER_H


#include "Network/Server/server.h"

//类似于server的controller

class ServerController
{
public:
    ServerController();

    static Server* getServerInstance();//保证连接的是一个数据库
private:
    static Server* _server;
};

#endif // SERVERCONTROLLER_H
