#include "widget.h"
#include "ui_widget.h"
#include "servercontroller.h"
#include "Utilities/log.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    Server* server = ServerController::getServerInstance();
    server->start(9999);

    //获得日志并写入
    connect(Log::GetLogObj(), &Log::readyShowLog, this, &Widget::showLog);
    //自动滚动日志区域
    connect(ui->textBrowser, SIGNAL(cursorPositionChanged()), this, SLOT(autoScroll()));
}


Widget::~Widget()
{
    delete ui;
}

void Widget::showLog(QString str){
    ui->textBrowser->append(str);
}

void Widget::autoScroll() {
    QTextCursor cursor =  ui->textBrowser->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->textBrowser->setTextCursor(cursor);
}
