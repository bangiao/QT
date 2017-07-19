#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPixmap pixmap(400, 300);
    QPainter p(&pixmap);
    
    // 填充背景颜色
    // p.fillRect(this->rect(), QBrush(Qt::white));
    pixmap.fill(Qt::white);
    
    p.drawPixmap(0, 0, 80, 80, QPixmap(":/new/prefix1/resource/1.png"));
    
    // 保存图片
    pixmap.save("../Image/pixmap.png");
}

Widget::~Widget()
{
    delete ui;
}
