#include "childwidget.h"

childwidget::childwidget(QWidget *parent) : QWidget(parent)
{
    resize(400, 300);
    setWindowTitle("子窗口");
    b.setText("创建父窗口");
    b.setParent(this);
    b.show();
    connect(&b, &QPushButton::released, this, &childwidget::myslot);
}

void childwidget::myslot()
{
    // 这个就是 发送信号  emit
    emit sendsignals();
}
