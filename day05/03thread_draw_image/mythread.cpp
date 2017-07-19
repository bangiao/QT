#include "mythread.h"
#include <QPen>
#include <QPainter>
#include <QBrush>

MyThread::MyThread(QObject *parent) : QObject(parent)
{
    
}

void MyThread::drawImageslots()
{
    QImage image(200, 200, QImage::Format_ARGB32);
    QPainter p(&image);
    
    QPen pen;
    pen.setWidth(5);
    
    p.setPen(pen);
    
    QBrush rush;
    rush.setStyle(Qt::SolidPattern);
    rush.setColor(Qt::red);
    p.setBrush(rush);
    
    QPoint a[] = {
        QPoint(qrand() % 200, qrand() % 200),  
        QPoint(qrand() % 200, qrand() % 200),  
        QPoint(qrand() % 200, qrand() % 200),  
        QPoint(qrand() % 200, qrand() % 200),  
        QPoint(qrand() % 200, qrand() % 200)
    };
    
    p.drawPolygon(a, 5);
    emit updateImageSignal(image);
}
