#include "MyPushButton.h"
#include <QMouseEvent>
#include <qDebug>

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{
    
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    static int num = 0;
    // 信号的抛弃
//    if (Qt::LeftButton == e->button())
//    {
//        qDebug() << "按下的是左键";
//    }
//    else 
//    {
//        // QPushButton::mousePressEvent(e);        
//    }
    
    // 本对象的这个信号忽略,直接传递到父组件 e->ignore(); 
    // 这个对象忽略这个信号, 这个信号继续向下发送
//    if (Qt::LeftButton == e->button())
//    {
//        qDebug() << "MyPushButton press";
//        e->ignore(); // 本对象的此信号会被忽略, 将信号继续往父组件(QWidget) 发送
//    }
//    else
//    {
//        // 不做处理
//        QPushButton::mousePressEvent(e);// 这个对象接收此信号
//    }
    
    // 信号的接收, 这样的话这个信号就被这个对象接收了, 不再发送到父组件
    if (Qt::LeftButton == e->button())
    {
        qDebug() << "MyPushButton press  " << num ++;
        // QPushButton::mousePressEvent(e);
        e->accept();  // 这个时候信号和槽函数失效
        QPushButton::mousePressEvent(e);
    }
}

//bool MyPushButton::event(QEvent *e)
//{
//    if (QEvent::MouseButtonPress == e->type())
//    {
//        return true;
//    }
//    if (QEvent::MouseButtonDblClick == e->type())
//    {
//        return true;
//    }
//    return QPushButton::event(e);
//}

