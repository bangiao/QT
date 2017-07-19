#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    
    QPicture pic;
    QPainter p;
    p.begin(&pic);
    
    p.drawPixmap(0, 0, 80, 80, 
                 QPixmap(":/new/prefix1/1.png"));
    p.drawLine(50, 50, 150, 50);
    
    p.end();
    
    // 保存的是二进制文件
    pic.save("../Image/picture.png");
}

void Widget::paintEvent(QPaintEvent *event)
{
#if 0
    QPicture pic;
    pic.load("../Image/picture.png");
    QPainter p(this);
    p.drawPicture(0, 0, pic);
#endif
    QPainter p(this);
    
    
    // QPixmap to QImage
    QPixmap pixmap;
    pixmap.load("../Image/picture.png");
    
    
    // 转换文件的类 QPixmap to QImage
    QImage tempimage = pixmap.toImage();
    p.drawImage(0, 0, tempimage);
    
    // QImage to QPixmap
    QImage image;
    image.load("../Image/picture.png");
    // QImage to QPixmap
    QPixmap tempPixmap = QPixmap::fromImage(image);
    p.drawPixmap(100, 0, tempPixmap);
}

Widget::~Widget()
{
    delete ui;
}
