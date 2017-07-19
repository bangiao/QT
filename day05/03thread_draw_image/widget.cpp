#include "widget.h"
#include "ui_widget.h"
#include <QPainter>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    
    this->m_myT = new MyThread;
    this->m_thread = new QThread(this);
    m_myT->moveToThread(m_thread);
    
    // 启动线程但是没有启动线程处理函数
    m_thread->start();
    // 线程处理函数必须通过 signal - slot 调用
    // 这个 connect 这样写的话, 他的槽函数是 m_myT 这个线程的东西
    // 所以这个槽函数是线程中的函数, 是属于线程的, 让线程去执行函数
    connect(ui->pushButton, &QPushButton::pressed, m_myT, &MyThread::drawImageslots);
    
    connect(m_myT, &MyThread::updateImageSignal, this, &Widget::getImage);
    
    connect(this, &Widget::destroyed, this->m_thread, [=](){
        this->m_thread->quit();
        this->m_thread->wait();
        delete this->m_myT;
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawImage(50, 50, m_image);
}

void Widget::getImage(QImage temp)
{
    m_image = temp;
    update();
}
