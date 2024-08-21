#include <QtDebug>
#include <QString>
#include "DataBase/datadb.h"
#include "Network/Handlers/LoginHandler.h"

#include "servercontroller.h"

#include "DataModel/datamodel.h"
#include "Utilities/utilities.h"

LoginHandler::LoginHandler(QObject *parent) : MsgHandler(parent)
{

}
void LoginHandler::parse(Msg& msg, TcpClientSocket* socket){
    Log::GetLogObj()->writeLog("[LoginHandler] Trying Parse");
    if (msg.getType() != MsgType::REQUEST_LOGIN) {
        Log::GetLogObj()->writeLog("Login msg error");
        return;
    }

    UserInfo tmp = UserInfo::fromQByteArray(msg.getContent());

	DataDB* db = DataDB::GetInstance();

    bool isLoginSuccess = db->selectUserByIdAndPwd(tmp.getID(), tmp.getPwd());
	MsgType type = isLoginSuccess ? MsgType::LOGIN_SUCCESS : MsgType::LOGIN_ERROR;

    if(isLoginSuccess){
        //如果登录成功了再将某客户端对应的socket添加到Server中.
        ServerController::getServerInstance()->addClient(tmp.getID(), socket);
        Log::GetLogObj()->writeLog("[LoginHandler] User " + QString::number(tmp.getID()) + " Successfully Logged in!");
        //并且还要返回用户的其他信息, 比如用户名和头像

        UserInfo tmp1 = db->selectUserInfoById(tmp.getID());
        tmp = UserInfo(tmp1.getID(),tmp1.getName(),tmp.getPwd(),tmp1.getAvatarName());
    }else{
        Log::GetLogObj()->writeLog("[LoginHandler] User " + QString::number(tmp.getID()) + " Logged Failed!");
    }
    socket->sendMessage(new Msg(type,tmp.toQByteArray()));
    Log::GetLogObj()->writeLog("[LoginHandler] Sent");
}
