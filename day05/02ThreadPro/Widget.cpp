#include "Widget.h"
#include "ui_Widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_myThread = new MyThread;
    m_thread = new QThread(this);
    
    m_myThread->moveToThread(m_thread);
    
    connect(m_myThread, &MyThread::mySignal, this, &Widget::dealSignal);
    
    qDebug() << "主线程的 ID: " << QThread::currentThread();
    
    // 当 widget 窗口的信号发送, 接着曹函数
    connect(this, &Widget::startTread_Signal, m_myThread, &MyThread::myTimerslots, );
    
    // 关闭窗口时, 结束线程
    connect(this, &Widget::destroyed, [=](){
        m_myThread->setFlag(true);
        m_thread->quit();// 用这个的话, 线程不急于关闭自己, 先将线程要做的事情做完
        m_thread->wait();// 等待线程结束
        delete m_myThread;
        m_myThread = NULL;
    });
    
    // 线程处理函数内部,  不允许操作图形界面
    
    // connect() 第五个参数的作用, 链接方式 默认, 队列, 直接
    // 多线程时才有意义
    // 默认的时候
    // 如果时多线程, 默认使用队列
    // 如果时单线程, 默认使用直接方式
    // 队列: 槽函数所在的线程和接受者一样
    // 直接: 槽函数所在的线程和发送者一样
    
}

Widget::~Widget()
{
    delete ui;
}

void Widget::dealSignal()
{
    static int i = 0;
    i++;
    ui->lcdNumber->display(i);
}

void Widget::on_pushButton_clicked()
{
    if (true == m_thread->isRunning())
    {
        return ;
    }
    m_thread->start();
    m_myThread->setFlag(false);
    emit startTread_Signal();
}

void Widget::on_pushButton_2_clicked()
{
    if (false == m_thread->isRunning())
    {
        return ;
    }
    m_myThread->setFlag(true);
    m_thread->quit();
    m_thread->wait();
}
