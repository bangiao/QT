#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QRgb>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    
    QImage image(400, 300, QImage::Format_ARGB32);
    QPainter p;
    p.begin(&image);
    
    p.drawImage(0, 0, QImage(":/new/prefix1/1.png"));
    
    
    // 对绘图设备前50个像素点进行操作
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            image.setPixel(i, j, qRgb(0, 255, 255));
            // image.pixel(i, j);
        }
    }
    
    p.end();
    
    image.save("../Image/image.png");
}

Widget::~Widget()
{
    delete ui;
}
