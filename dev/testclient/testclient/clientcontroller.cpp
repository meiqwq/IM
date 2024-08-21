#include "clientcontroller.h"


ClientController::ClientController(QObject* parent) : QObject(parent)
{

}

//初始化客户端的Socket
TcpClientSocket* ClientController::socket = NULL;

TcpClientSocket* ClientController::GetSocket() {
	if (socket == NULL) {
		socket = new TcpClientSocket();
	}
	return socket;
}

void ClientController::ConnectToServer() {
	TcpClientSocket* clientSocket = GetSocket();
	clientSocket->setServerIP("127.0.0.1");
	clientSocket->setServerTcpPort("9999");
	if (!clientSocket->connectToServer()) {
		qDebug() << "[connectToServer] Connection Failed.";
	}
	else {
		qDebug() << "[connectToServer] Connection Successful.";
	}
}

void ClientController::clientInitialize() {
	HandlerConnect();
	//暂时没有把连接服务器放在这里.
}

void ClientController::InitChatMsgList(quint32 id) {

}

QList<ChatMessage> ClientController::GetChatMsgList(quint32 id) {
	return QList<ChatMessage>();
}
