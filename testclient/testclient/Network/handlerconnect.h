#ifndef HANDLERCONNECT_H
#define HANDLERCONNECT_H

#include <QObject>

//暂时没有东西, 直接去HandlerConnect.cpp里写connect函数即可.
class HandlerConnect : public QObject
{
    Q_OBJECT
public:
    explicit HandlerConnect(QObject *parent = nullptr);

signals:

};

#endif // HANDLERCONNECT_H
