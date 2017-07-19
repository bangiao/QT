#include "MyWidget.h"
#include <QString>
#include <qDebug>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    int num = 10;
    resize(400, 300);
    this->setWindowTitle("父窗口");
    
    button.setText("打开子窗口");
    button.setParent(this);
    button.show();
    
    
    // 这这个函数没有大问题, 但是这个地方使用了 [&] 的捕捉方式, 会导致 前文的变量值不确定
    //    connect(&button, &QPushButton::released, this, [&]()
    //    {
    //        w.show();
    //        this->hide();
    //    });
    
    //    void (ChildWidget::*func1)(int, QString) = ChildWidget::sendsignals;
    //    connect(&w, func1, this, [&](int num, QString str)
    //    {
    //        w.hide();
    //        this->show();
    //        num++;
    //        qDebug() << num << "  " << str.toUtf8().data();
    //    });
    
    
    
    
    QPushButton *but = new QPushButton("zhazha", this);
    
    connect(but, &QPushButton::clicked, this, [=](bool IsCheck) mutable
    {
        // qDebug() << IsCheck;
        if (false == IsCheck)
        {
            w.show();
            this->hide();
            qDebug() << num;
        }
    });
    
    void (ChildWidget::*func1)(int, QString) = ChildWidget::sendsignals;
    connect(&w, func1, this, [=](int num, QString str)
    {
        w.hide();
        this->show();
        qDebug() << num << "  " << str.toUtf8().data();
    });
    
    
}
