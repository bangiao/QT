#include "MyContrl.h"
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>

MyContrl::MyContrl(QWidget *parent) : QWidget(parent)
{
    // 自定义样式
    QSlider *lisder = new QSlider(Qt::Orientation::Horizontal, this);
    QSpinBox *spin = new QSpinBox(this);
    
    lisder->setRange(0, 100);
    spin->setRange(0, 100);
    
    QHBoxLayout *h_layout = new QHBoxLayout(this);
    h_layout->addWidget(spin);
    h_layout->addWidget(lisder);
    
    connect(spin, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), 
            lisder, &QSlider::setValue);
    connect(lisder, static_cast<void (QSlider::*)(int)>(&QSlider::valueChanged),
            spin, &QSpinBox::setValue);    
}
