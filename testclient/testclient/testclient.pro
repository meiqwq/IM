QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DataModel/Msg/msg.cpp \
    DataModel/chatmessage.cpp \
    DataModel/userinfo.cpp \
    Network/Handlers/chatmsghandler.cpp \
    Network/Handlers/clientloginhandler.cpp \
    Network/Handlers/clientregisterhandler.cpp \
    Network/handlerconnect.cpp \
    Network/handlerreg.cpp \
    Network/tcpclientsocket.cpp \
    Utilities/log.cpp \
    Utilities/qbytearraylistutility.cpp \
    Utilities/safeutilities.cpp \
    Utilities/verifyutilities.cpp \
    clientcontroller.cpp \
    clientcontroller_chat.cpp \
    clientcontroller_reg_login.cpp \
    widget.cpp \
    main.cpp

HEADERS += \
    DataModel/Msg/msg.h \
    DataModel/Msg/msgtype.h \
    DataModel/chatmessage.h \
    DataModel/datamodel.h \
    DataModel/userinfo.h \
    Network/Handlers/chatmsghandler.h \
    Network/Handlers/clientloginhandler.h \
    Network/Handlers/clientregisterhandler.h \
    Network/Handlers/handlers.h \
    Network/Handlers/msghandler.h \
    Network/handlerconnect.h \
    Network/handlerreg.h \
    Network/tcpclientsocket.h \
    Utilities/log.h \
    Utilities/qbytearraylistutility.h \
    Utilities/safeutilities.h \
    Utilities/standarddatetimeutilities.h \
    Utilities/utilities.h \
    Utilities/verifyutilities.h \
    clientcontroller.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
