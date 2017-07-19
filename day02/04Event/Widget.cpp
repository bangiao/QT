#include "Widget.h"
#include "ui_widget.h"
#include "MyPushButton.h"
#include <QEvent> 
#include <qDebug>
#include <QKeyEvent>
#include <QString>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    time_id = this->startTimer(1000);
    connect(ui->pushButton, &MyPushButton::clicked, this, [=](){
        qDebug() << "按钮按下";
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::keyPressEvent(QKeyEvent *ev)
{
    qDebug() << "Widget press";
}

void Widget::timerEvent(QTimerEvent *event)
{
    static int sec = 0;
    if (10 == sec)
    {
        killTimer(time_id);
    }
    ui->label_2->setText(QString("<center>%1</center>").arg(sec++));
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "QWidget press";
}

void Widget::closeEvent(QCloseEvent *event)
{
    int ret = QMessageBox::question(this, "提示: ", "时候退出程序?");
    if (QMessageBox::Yes == ret)
    {
        event->accept();// 接收信号, 信号以默认的方式继续传输
    }
    else if (QMessageBox::No == ret)
    {
        event->ignore(); // 忽略信号, 信号直接传输到父组件
    }
}

bool Widget::event(QEvent *event)
{
    // 事件的分发
    if (event->type() == QEvent::Timer)
    {
        // 干掉定时器的使用
        // 如果返回值为 true 的话, 事件停止传播
        return true;
    }
    // 这里企图去拦截 子类的信号, 但是这个是基类, 信号还是会发送给子类, 子类也有自己的基类, 所以和这个美观么关系
    // 根据多态的原理, 程序会去调用 QPushButton 的 event 函数
    if (QEvent::MouseButtonPress == event->type())
    {
        return true;
    }
    if (QEvent::MouseButtonDblClick == event->type())
    {
        return true;
    }
    QWidget::event(event);
}




















