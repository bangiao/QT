#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include "mythread.h"
#include <QThread>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
    void paintEvent(QPaintEvent *event);
    
    void getImage(QImage );
    
private:
    Ui::Widget *ui;
    QImage m_image;
    MyThread *m_myT;
    QThread *m_thread;
};

#endif // WIDGET_H
