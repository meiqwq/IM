#include "tcpclientsocket.h"
#include <QHostAddress>
#include <QDataStream>

#include "serverhandlerreg.h"

TcpClientSocket::TcpClientSocket(QObject *parent) :
    QTcpSocket(parent),_blockSize(0)
{
    connect(this, SIGNAL(readyRead()),this, SLOT(receiveMessage()));
}
void TcpClientSocket::setServerIP(const QString & serverIP)
{
    _serverIP = serverIP;
}

void TcpClientSocket::setServerTcpPort(const QString & serverTcpPort)
{
    _serverTcpPort = serverTcpPort.toInt();
}

QString TcpClientSocket::getServerIP()
{
    return _serverIP;
}

QString TcpClientSocket::getServerPort()
{
    return QString::number(_serverTcpPort);
}

bool TcpClientSocket::testConnect()
{
    disconnectFromHost();
    connectToHost(QHostAddress(this->_serverIP),this->_serverTcpPort);
    bool ret = waitForConnected();
    disconnectFromHost();
    return ret;
}

bool TcpClientSocket::connectToServer()
{
    bool ret = true;
    abort();
    if( (ret = testConnect()) == false )
    {
        return ret;
    }
    connectToHost(QHostAddress(this->_serverIP),this->_serverTcpPort);
    return ret;
}

void TcpClientSocket::sendMessage(Msg* message)
{
    write(message->toQByteArray());
}

void TcpClientSocket::receiveMessage()
{
    QByteArray buf = readAll();
    Msg tmp = Msg::fromFullQByteArray(buf);
	if (tmp.getType() == MsgType::UNDEFINED) return;
    MsgHandler * tmp_handler = ServerHandlerReg::GetRegObj()->getHandler(tmp.getType());
	qDebug() << (quint32)(MsgType::REQUEST_LOGIN) << " " << (quint32)tmp.getType();
    tmp_handler->parse(tmp,qobject_cast<TcpClientSocket *>(sender()));
}

