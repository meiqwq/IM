QT       += core gui
QT       += network
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DataBase/datadb.cpp \
    DataModel/Msg/msg.cpp \
    DataModel/chatmessage.cpp \
    DataModel/userinfo.cpp \
    Network/Handlers/LoginHandler.cpp \
    Network/Handlers/RegisterHandler.cpp \
    Network/Handlers/chatmsghandler.cpp \
    Network/Server/server.cpp \
    Network/Server/tcpserver.cpp \
    Network/serverhandlerreg.cpp \
    Network/tcpclientsocket.cpp \
    Utilities/log.cpp \
    Utilities/qbytearraylistutility.cpp \
    main.cpp \
    servercontroller.cpp \
    widget.cpp

HEADERS += \
    DataBase/datadb.h \
    DataModel/Msg/msg.h \
    DataModel/Msg/msgtype.h \
    DataModel/chatmessage.h \
    DataModel/datamodel.h \
    DataModel/userinfo.h \
    Network/Handlers/LoginHandler.h \
    Network/Handlers/RegisterHandler.h \
    Network/Handlers/chatmsghandler.h \
    Network/Handlers/msghandler.h \
    Network/Server/server.h \
    Network/Server/tcpserver.h \
    Network/serverhandlerreg.h \
    Network/tcpclientsocket.h \
    Utilities/log.h \
    Utilities/qbytearraylistutility.h \
    Utilities/standarddatetimeutilities.h \
    Utilities/utilities.h \
    servercontroller.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
