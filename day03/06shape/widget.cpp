#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    
    // 去窗口边框
    // setWindowFlags(Qt::Dialog);// 创建对话框  
    // FramelessWindowHint 无边框窗口提示
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    
    // 设置窗口背景 透明
    setAttribute(Qt::WA_TranslucentBackground);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(0, 0, QPixmap(":/new/prefix1/1.png"));
    
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    {
        // ruguoshi youjian
        close();
    }
    else if (event->button() == Qt::LeftButton)
    {
        // qiuzuobiao chazhi 
        // dangqina dianji zuobiao chuangkou zuoshangbiao de zuobiao 
        p = event->globalPos() - this->frameGeometry().topLeft();
        
    }
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() & Qt::LeftButton)
    {
        move(event->globalPos() - p);
    }
}
