#include "servercontroller.h"

Server* ServerController::_server = NULL;

ServerController::ServerController()
{
}

Server* ServerController::getServerInstance()
{
    if(_server == NULL)
    {
        _server = new Server;
    }
    return _server;
}
