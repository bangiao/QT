#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QBitmap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(500, 500);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    // 画家
    QPainter p(this);
    
    // QPixmap 
    p.drawPixmap(0, 0, QPixmap(":/new/prefix1/resouce/1.png"));
    
    p.drawPixmap(200, 0, QBitmap(":/new/prefix1/resouce/1.png"));
    
    
    QPixmap pixmap;
    pixmap.load(":/new/prefix1/resouce/1.png");
    p.drawPixmap(0, 200, pixmap);
    
    QBitmap bitmap;
    bitmap.load(":/new/prefix1/resouce/1.png");
    p.drawPixmap(200, 200, bitmap);
    
}











