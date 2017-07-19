#include "widget.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <qDebug>
#define cout (qDebug() << "{" << __FILE__ << ":" << __LINE__ << "}")

// :/new/prefix1/resource/2.jpg

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(600, 600);
}

Widget::~Widget()
{
    
}

void Widget::drawGrid()
{
    QPainter painter(this);
    QPen pen(Qt::SolidLine);
    pen.setWidth(10);
    
    painter.setPen(pen);
    
    // shu zhe    x zou bian y zou bubian 
    for (int i = 0; i < 9; i++)
    {
        painter.drawLine(start_x + (i * grid_x), start_y, 
                         start_x + (i * grid_x), start_y + (grid_y * 9));
    }
    
    // heng zhe x zou bu bian y zou bian 
    for (int i = 0; i < 10; i ++)
    {
        painter.drawLine(start_x, start_y + (i * grid_y), 
                         start_x + (grid_x * 8), start_y + (i * grid_y));
    }
}

void Widget::paintEvent(QPaintEvent *event)
{
    this->start_x = width() / 10;
    this->grid_x = this->start_x;
    this->start_y = height() / 11;
    this->grid_y = this->start_y;
    
    QPainter p(this);
    p.drawPixmap(this->rect(), QPixmap(":/new/prefix1/resource/background.jpg"));
    // 画网格
    drawGrid();
    PointToPosition();
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->x() > this->start_x && event->x() < this->start_x + 8 * grid_x &&
            event->y() > this->start_y && event->y() < this->start_y + 9 * grid_y)
    {
        this->x = event->x();
        this->y = event->y();
        repaint();
    }
}

void Widget::PointToPosition()
{
    QPainter p(this);
    int x1 = this->start_x;
    int x2 = x1 + grid_x;
    int y1 = this->start_y;
    int y2 = y1 + grid_y;
    
    int x_pos = -1;
    int y_pos = -1;
    
    // 比较菜的一种思路
//    for (; x1 < width(); x1 += this->grid_x, x2 += grid_x)
//    {
//        if (this->x > x1 && this->x < x2)
//        {
//            // 找到这个位置的 x 轴了, 算出这个地方大致的中心点x轴坐标
//            x_pos = (x1 + x2) / 2;
//            break;
//        }
//    }    
//    for (; y1 < height(); y1 += this->grid_y , y2 += this->grid_y)
//    {
//        if (this->y > y1 && this->y < y2)
//        {
//            // 算出这个位置的大致中心点坐标 y
//            y_pos = (y1 + y2) / 2;
//            break;
//        }
//    }
    
    
    // 核心思想
    x_pos = (this->x - this->start_x) / grid_x;
    y_pos = (this->y - this->start_y) / grid_y;
    
    
    if (-1 != x_pos && -1 != y_pos)
    {
        p.drawPixmap(this->start_x + x_pos * this->grid_x, 
                     this->start_y + this->grid_y * y_pos, 
                     this->grid_x, this->grid_y, QPixmap(":/new/prefix1/resource/2.jpg"));
    }
    
    // 比较菜的一种思路
//    if (-1 != x_pos && -1 != y_pos)
//    {
//        p.drawPixmap(x1, y1, this->grid_x, this->grid_y, QPixmap(":/new/prefix1/resource/2.jpg"));
//    }
}












