#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "DataModel/datamodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void on_login_button_clicked();

    void on_register_button_clicked();

    //日志小窗口的槽函数
    void showLog(QString);

    void autoScroll();

private slots:
    //显示注册登录状态的槽函数
    void showRegisterSuccessful(UserInfo info);
    void showRegisterFailed();

    void showLoginSuccessful(UserInfo info);
    void showLoginFailed();

    void on_pushButton_clicked();

    //显示消息的槽函数
    void showChatMessage(ChatMessage msg);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
