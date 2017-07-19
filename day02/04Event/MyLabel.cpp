#include "MyLabel.h"
#include <qDebug>
#include <QMouseEvent>
#include <QEvent>
#include <QKeyEvent>
#include <Qstring>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    this->setMouseTracking(true);
    resize(400, 300);
}

void MyLabel::mousePressEvent(QMouseEvent *event)
{
    int i = event->x();
    int j = event->y();
    QString  text = QString("<center><h1>Mouse Press: (%1, %2)</h1></center>")
            .arg(i).arg(j);
    this->setText(text);
    // 全局的坐标
    QPoint point = event->globalPos();
    qDebug() << point.x() << " " << point.y();
    
    if (Qt::RightButton == event->button())
    {
        qDebug() << "Right" ;
    }
    else if (Qt::LeftButton == event->button())
    {
        qDebug() << "Left" ;
    }
    else if (Qt::MidButton == event->button())
    {
        qDebug() << "Mid" ;
    }
    
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    int i = ev->x();
    int j = ev->y();
    
    QString  text = QString("<center><h1>Mouse Press: (%1, %2)</h1></center>")
            .arg(i).arg(j);
    // this->setText(text);
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    this->setText("mouseReleaseEvent");
}

void MyLabel::enterEvent(QEvent *event)
{
    this->setText("enterEvent");
}

void MyLabel::leaveEvent(QEvent *event)
{
    this->setText("leaveEvent");
}
