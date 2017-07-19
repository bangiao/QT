#include "widget.h"
#include "ui_widget.h"
#include <QThread>
#include <QDebug>

/*
这个线程的主要想法就是:
新加一个线程的文件, 在内部写上复杂的操作, 通过操作结束发送信号 
   IsDoneSignal 通知主线程复杂操作结束
*/

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_timer = new QTimer(this);
    
    connect(m_timer, &QTimer::timeout, this, &Widget::dealTimeOut);
    
    // 分配空间
    m_thread = new MyThread(this);
    
    connect(m_thread, &MyThread::isDoneSignal, this, &Widget::dealDoneSignal);
    // 当床窗口关闭时触发 destroyed 信号
    connect(this, &Widget::destroyed, this, &Widget::stopThread);
    
}

void Widget::dealDoneSignal()
{
    qDebug() << "it is over";
    m_timer->stop();
}

void Widget::stopThread()
{
    // 停止线程
    m_thread->quit();
    // 等待线程处理完手头的工作
    m_thread->wait();
}

void Widget::dealTimeOut()
{
    static int i = 0;
    
    i++;
    
    ui->lcdNumber->display(i);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    if (m_timer->isActive() == false)
    {
        m_timer->start(100);
    }
    // 启动线程
    m_thread->start();
}
