#include "MyWidget.h"
#include <QApplication>
#include <QLineEdit>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    QLineEdit *edit1 = new QLineEdit();
    QLineEdit *edit2 = new QLineEdit();
    QLineEdit *edit3 = new QLineEdit();
    QGridLayout *glayout = new QGridLayout();
    
    this->setLayout(glayout);
    glayout->addWidget(edit1, 0, 0);
    glayout->addWidget(edit2, 0, 1);
    glayout->addWidget(edit3, 0, 2);
    edit1->setMinimumWidth(50);
    edit2->setMinimumWidth(100);
    edit3->setMinimumWidth(50);
    glayout->setColumnStretch(3, 1);
    glayout->setRowStretch(1, 1);
    
#if 0
    QVBoxLayout *vlayout = new QVBoxLayout();
    QHBoxLayout *layout = new QHBoxLayout();
    this->setLayout(vlayout);
    layout->addWidget(edit1, 1);
    edit1->setMinimumWidth(50);
    layout->addWidget(edit2, 2);
    edit2->setMinimumWidth(100);
    layout->addWidget(edit3, 1);
    edit3->setMinimumWidth(50);
    layout->addStretch(10000);
    vlayout->addLayout(layout);
    vlayout->addStretch(1);
#endif
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWidget w;
    w.show();
    return app.exec();
}
