#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->m_myTimer = new QTimer(this);
    
    connect(this->m_myTimer, &QTimer::timeout, [=](){
        static int i = 0;
        i++;
        ui->lcdNumber->display(i);
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    // 启动定时器
    // 时间间隔为 100 ms
    // 每隔 100 ms 定时器 对象自动触发 timeout() 信号
    // 如果定时器没有激活, 才启动
    if (this->m_myTimer->isActive() == false)
    {
        this->m_myTimer->start(100);
    }
}

void Widget::on_pushButton_2_clicked()
{
    if (true == this->m_myTimer->isActive())
    {
        this->m_myTimer->stop();
    }
}
