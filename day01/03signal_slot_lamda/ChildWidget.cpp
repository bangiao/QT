#include "ChildWidget.h"

ChildWidget::ChildWidget(QWidget *parent) : QWidget(parent)
{
    resize(400 ,300);
    this->setWindowTitle("子窗口");
    button.setText("打开父窗口");
    button.setParent(this);
    button.show();
    
    connect(&button, &QPushButton::released, this, [&](){
        emit sendsignals(10, "握草");
    });
}
