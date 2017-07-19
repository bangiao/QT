#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = 0);
    
protected:
    void mousePressEvent(QMouseEvent *e);
//    bool event(QEvent *e);
signals:
    
public slots:
};

#endif // MYPUSHBUTTON_H
