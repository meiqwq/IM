#include "widget.h"
#include "ui_widget.h"

#include "DataModel/datamodel.h"
#include "clientcontroller.h"

#include "Utilities/log.h"
#include "Network/handlerreg.h"

#include <QObject>
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //获得日志并写入
    connect(Log::GetLogObj(), &Log::readyShowLog, this, &Widget::showLog);
    //自动滚动日志区域
    connect(ui->recvMsgtextBrowser, SIGNAL(cursorPositionChanged()), this, SLOT(autoScroll()));
    ClientController::clientInitialize(); //内部调用handlerconnect 暂时没有把connect放在里面

    connect( (ClientRegisterHandler *) HandlerReg::GetRegObj()->getHandler(MsgType::REGISTER_SUCCESS),
            &ClientRegisterHandler::sigRegSuccessful,
            this,
            &Widget::showRegisterSuccessful
            );

    connect( (ClientRegisterHandler *) HandlerReg::GetRegObj()->getHandler(MsgType::REGISTER_ERROR),
            &ClientRegisterHandler::sigRegFailed,
            this,
            &Widget::showRegisterFailed
            );

    connect( (ClientLoginHandler *) HandlerReg::GetRegObj()->getHandler(MsgType::LOGIN_SUCCESS),
            &ClientLoginHandler::sigLoginSuccessful,
            this,
            &Widget::showLoginSuccessful
            );

    connect( (ClientLoginHandler *) HandlerReg::GetRegObj()->getHandler(MsgType::LOGIN_ERROR),
            &ClientLoginHandler::sigLoginFailed,
            this,
            &Widget::showLoginFailed
            );

    connect( (ChatMsgHandler *) HandlerReg::GetRegObj()->getHandler(MsgType::MSG_PLAIN_TEXT),
            &ChatMsgHandler::readyShowChatMsg,
            this,
            &Widget::showChatMessage
            );


    HandlerReg::GetRegObj()->getHandler(MsgType::REGISTER_SUCCESS);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_login_button_clicked()
{
    quint32 id = ui->login_id->text().toUInt();
    QString pw = ui->login_pw->text();
    ClientController::SendLoginRequest(id, pw);
}

void Widget::on_register_button_clicked()
{
    qDebug() << "Clicking Register Button";
    QString username = ui->reg_name->text();
    QString pw = ui->reg_pw->text();
    ClientController::SendRegisterRequest(username, pw);
}


//日志小窗口的槽函数
void Widget::showLog(QString str){
    ui->recvMsgtextBrowser->append(str);
}

void Widget::autoScroll() {
    QTextCursor cursor =  ui->recvMsgtextBrowser->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->recvMsgtextBrowser->setTextCursor(cursor);
}


//接收注册登录的槽函数
void Widget::showRegisterSuccessful(UserInfo info){
    QString caption = "注册成功";
    ui->status->setText(caption);
    QString tmp = caption + "! \n您的账号是 " +
                  QString::number(info.getID()) +
                  "\n请牢记此账号用于登录.";
    QMessageBox::warning(NULL,caption,tmp);
}

void Widget::showRegisterFailed(){
    QString caption = "注册失败";
    ui->status->setText(caption);
    QString tmp = caption + "! "
                            "\n您的用户名或者密码可能不符合要求.";
    QMessageBox::warning(NULL,caption,tmp);
}

void Widget::showLoginSuccessful(UserInfo info){
    QString caption = "登录成功";
    ui->status->setText(caption);
    QString tmp = caption + "! \n欢迎您! " +
                  info.getName() +
                  "";
    ui->info_id->setText(QString::number(info.getID()));
    ui->info_pw->setText(info.getPwd());
    ui->info_name->setText(info.getName());
    QMessageBox::warning(NULL,caption,tmp);
}

void Widget::showLoginFailed(){
    QString caption = "登录失败";
    ui->status->setText(caption);
    QString tmp = caption + "! "
                            "\n账号或密码输入错误.";
    QMessageBox::warning(NULL,caption,tmp);
}

void Widget::on_pushButton_clicked()
{
    ClientController::SendChatMessage(ui->sendMsg_recvID->text().toUInt(),
                                      ui->MsgContentplainTextEdit->document()->toPlainText());
}

void Widget::showChatMessage(ChatMessage msg){
    qDebug() << msg.getSender();
    Log::GetLogObj()->writeLog("[" + QString::number(msg.getSender()) + "] 对你说 : " + msg.getContent());
}
