#include "mywidget.h"

mywidget::mywidget(QWidget *parent) : QWidget(parent)
{
    resize(400, 300);
    b.setText("开启子窗口");
    b.setParent(this);
    b.show();
    
    connect(&b, &QPushButton::released, this, &mywidget::create_child_slot);
    connect(&w, &childwidget::sendsignals, this, &mywidget::create_parent_slot);
}

void mywidget::create_child_slot()
{
    this->hide();
    w.show();
}

void mywidget::create_parent_slot()
{
    w.hide();
    this->show();
}
