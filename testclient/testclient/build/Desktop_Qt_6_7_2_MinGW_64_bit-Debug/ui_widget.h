/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *login_button;
    QPushButton *register_button;
    QWidget *layoutWidget;
    QGridLayout *RegArea;
    QLabel *label_3;
    QLineEdit *reg_name;
    QLabel *label_4;
    QLineEdit *reg_pw;
    QLabel *RegTip;
    QLabel *MyInfo;
    QWidget *layoutWidget1;
    QGridLayout *MyInfoArea;
    QLabel *label_info_id;
    QLineEdit *info_id;
    QLabel *label_info_name;
    QLineEdit *info_name;
    QLabel *label_info_pw;
    QLineEdit *info_pw;
    QWidget *layoutWidget2;
    QGridLayout *LoginArea;
    QLabel *label_id;
    QLineEdit *login_id;
    QLabel *label_pw;
    QLineEdit *login_pw;
    QWidget *layoutWidget3;
    QHBoxLayout *StatusArea;
    QLabel *label_7;
    QLineEdit *status;
    QWidget *layoutWidget4;
    QVBoxLayout *SendMsgArea;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *sendto;
    QLineEdit *sendMsg_recvID;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QPlainTextEdit *MsgContentplainTextEdit;
    QWidget *layoutWidget5;
    QVBoxLayout *RecvMsgArea;
    QLabel *label_8;
    QTextBrowser *recvMsgtextBrowser;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(655, 447);
        login_button = new QPushButton(Widget);
        login_button->setObjectName("login_button");
        login_button->setGeometry(QRect(110, 100, 93, 28));
        register_button = new QPushButton(Widget);
        register_button->setObjectName("register_button");
        register_button->setGeometry(QRect(110, 260, 93, 28));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 170, 171, 56));
        RegArea = new QGridLayout(layoutWidget);
        RegArea->setObjectName("RegArea");
        RegArea->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        RegArea->addWidget(label_3, 0, 0, 1, 1);

        reg_name = new QLineEdit(layoutWidget);
        reg_name->setObjectName("reg_name");

        RegArea->addWidget(reg_name, 0, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        RegArea->addWidget(label_4, 1, 0, 1, 1);

        reg_pw = new QLineEdit(layoutWidget);
        reg_pw->setObjectName("reg_pw");
        reg_pw->setEchoMode(QLineEdit::EchoMode::Password);

        RegArea->addWidget(reg_pw, 1, 1, 1, 1);

        RegTip = new QLabel(Widget);
        RegTip->setObjectName("RegTip");
        RegTip->setGeometry(QRect(30, 230, 171, 24));
        MyInfo = new QLabel(Widget);
        MyInfo->setObjectName("MyInfo");
        MyInfo->setGeometry(QRect(30, 300, 171, 24));
        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(30, 330, 171, 86));
        MyInfoArea = new QGridLayout(layoutWidget1);
        MyInfoArea->setObjectName("MyInfoArea");
        MyInfoArea->setContentsMargins(0, 0, 0, 0);
        label_info_id = new QLabel(layoutWidget1);
        label_info_id->setObjectName("label_info_id");

        MyInfoArea->addWidget(label_info_id, 0, 0, 1, 1);

        info_id = new QLineEdit(layoutWidget1);
        info_id->setObjectName("info_id");
        info_id->setEnabled(false);

        MyInfoArea->addWidget(info_id, 0, 1, 1, 1);

        label_info_name = new QLabel(layoutWidget1);
        label_info_name->setObjectName("label_info_name");

        MyInfoArea->addWidget(label_info_name, 1, 0, 1, 1);

        info_name = new QLineEdit(layoutWidget1);
        info_name->setObjectName("info_name");
        info_name->setEnabled(false);

        MyInfoArea->addWidget(info_name, 1, 1, 1, 1);

        label_info_pw = new QLabel(layoutWidget1);
        label_info_pw->setObjectName("label_info_pw");

        MyInfoArea->addWidget(label_info_pw, 2, 0, 1, 1);

        info_pw = new QLineEdit(layoutWidget1);
        info_pw->setObjectName("info_pw");
        info_pw->setEnabled(false);

        MyInfoArea->addWidget(info_pw, 2, 1, 1, 1);

        layoutWidget2 = new QWidget(Widget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(30, 30, 171, 56));
        LoginArea = new QGridLayout(layoutWidget2);
        LoginArea->setObjectName("LoginArea");
        LoginArea->setContentsMargins(0, 0, 0, 0);
        label_id = new QLabel(layoutWidget2);
        label_id->setObjectName("label_id");

        LoginArea->addWidget(label_id, 0, 0, 1, 1);

        login_id = new QLineEdit(layoutWidget2);
        login_id->setObjectName("login_id");

        LoginArea->addWidget(login_id, 0, 1, 1, 1);

        label_pw = new QLabel(layoutWidget2);
        label_pw->setObjectName("label_pw");

        LoginArea->addWidget(label_pw, 1, 0, 1, 1);

        login_pw = new QLineEdit(layoutWidget2);
        login_pw->setObjectName("login_pw");
        login_pw->setEchoMode(QLineEdit::EchoMode::Password);

        LoginArea->addWidget(login_pw, 1, 1, 1, 1);

        layoutWidget3 = new QWidget(Widget);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(230, 30, 171, 26));
        StatusArea = new QHBoxLayout(layoutWidget3);
        StatusArea->setObjectName("StatusArea");
        StatusArea->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget3);
        label_7->setObjectName("label_7");

        StatusArea->addWidget(label_7);

        status = new QLineEdit(layoutWidget3);
        status->setObjectName("status");
        status->setEnabled(false);

        StatusArea->addWidget(status);

        layoutWidget4 = new QWidget(Widget);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(230, 70, 191, 351));
        SendMsgArea = new QVBoxLayout(layoutWidget4);
        SendMsgArea->setObjectName("SendMsgArea");
        SendMsgArea->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        sendto = new QLabel(layoutWidget4);
        sendto->setObjectName("sendto");

        horizontalLayout_2->addWidget(sendto);

        sendMsg_recvID = new QLineEdit(layoutWidget4);
        sendMsg_recvID->setObjectName("sendMsg_recvID");
        sendMsg_recvID->setEchoMode(QLineEdit::EchoMode::Normal);

        horizontalLayout_2->addWidget(sendMsg_recvID);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        pushButton = new QPushButton(layoutWidget4);
        pushButton->setObjectName("pushButton");

        horizontalLayout_3->addWidget(pushButton);


        SendMsgArea->addLayout(horizontalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_2 = new QLabel(layoutWidget4);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        MsgContentplainTextEdit = new QPlainTextEdit(layoutWidget4);
        MsgContentplainTextEdit->setObjectName("MsgContentplainTextEdit");

        verticalLayout->addWidget(MsgContentplainTextEdit);


        SendMsgArea->addLayout(verticalLayout);

        layoutWidget5 = new QWidget(Widget);
        layoutWidget5->setObjectName("layoutWidget5");
        layoutWidget5->setGeometry(QRect(440, 30, 191, 391));
        RecvMsgArea = new QVBoxLayout(layoutWidget5);
        RecvMsgArea->setObjectName("RecvMsgArea");
        RecvMsgArea->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget5);
        label_8->setObjectName("label_8");

        RecvMsgArea->addWidget(label_8);

        recvMsgtextBrowser = new QTextBrowser(layoutWidget5);
        recvMsgtextBrowser->setObjectName("recvMsgtextBrowser");

        RecvMsgArea->addWidget(recvMsgtextBrowser);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\345\256\242\346\210\267\347\253\257\346\216\247\345\210\266\345\231\250", nullptr));
        login_button->setText(QCoreApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
        register_button->setText(QCoreApplication::translate("Widget", "\346\263\250\345\206\214", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\345\257\206\347\240\201", nullptr));
        RegTip->setText(QCoreApplication::translate("Widget", "\346\232\202\344\270\215\350\200\203\350\231\221\351\207\215\345\244\215\345\257\206\347\240\201", nullptr));
        MyInfo->setText(QCoreApplication::translate("Widget", "\346\210\221\347\232\204\344\277\241\346\201\257", nullptr));
        label_info_id->setText(QCoreApplication::translate("Widget", "\350\264\246\345\217\267", nullptr));
        label_info_name->setText(QCoreApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_info_pw->setText(QCoreApplication::translate("Widget", "\345\257\206\347\240\201", nullptr));
        label_id->setText(QCoreApplication::translate("Widget", "\350\264\246\345\217\267", nullptr));
        label_pw->setText(QCoreApplication::translate("Widget", "\345\257\206\347\240\201", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "\347\212\266\346\200\201:   ", nullptr));
        sendto->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\347\273\231", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\266\210\346\201\257\345\206\205\345\256\271", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "\345\256\242\346\210\267\347\253\257\346\227\245\345\277\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
