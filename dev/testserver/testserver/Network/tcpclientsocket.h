#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H
#include <QTcpSocket>
#include "DataModel/Msg/msg.h"

//code by BFZD

class TcpClientSocket:  public QTcpSocket
{
    Q_OBJECT
public:
    explicit TcpClientSocket(QObject *parent = 0);
    void setServerIP(const QString & serverIP);
    void setServerTcpPort(const QString &serverTcpPort);
    QString getServerIP();
    QString getServerPort();
    bool testConnect();
    bool connectToServer();
    void sendMessage(Msg * message);

signals:

public slots:
    void receiveMessage();
private:
    QString _serverIP;
    int _serverTcpPort;
    qint16 _blockSize;

};

#endif // TCPCLIENTSOCKET_H
