#include "Widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <qDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    x = 0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    //QPainter p(this);
    
    QPainter p;
    
    p.begin(this);
    
    //p.drawPixmap(this->rect(), QPixmap(":/new/prefix1/resoruce/tooopen_sy_127457023651.jpg"));
    
    // 画线
    QPen pen;
    pen.setWidth(5);
    pen.setColor(qRgb(14, 255, 255));
    pen.setStyle(Qt::DashLine);
    p.setPen(pen);
    p.drawLine(50, 50, 150, 50);
    p.drawLine(50, 50, 50, 150);
    
    // 创建画刷
    QBrush rush;
    rush.setColor(Qt::red);
    rush.setStyle(Qt::Dense1Pattern);
    
    p.setBrush(rush);
    
    // 画矩形
    p.drawRect(150, 150, 100, 50);
    
    // 画圆
    p.drawEllipse(QPoint(150, 150), 50, 25);
    
    
    // 画笑脸
    QPixmap pixmap(":/new/prefix1/resoruce/2.jpg");
    p.drawPixmap(x, 180, 80, 80, pixmap);
    
    // 获取图片的宽度, 以毫米为单位
    this->pic_width = pixmap.widthMM() / 2;
    // qDebug() << pixmap.width() / 2;
    
    p.end();
}

void Widget::on_pushButton_clicked()
{
    x += 20;
    if (x > width() - this->pic_width)
    {
        x = 0;
    }
    
    // 刷新窗口   重绘窗口
    //repaint();
    update();
}
