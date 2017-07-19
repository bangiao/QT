#include "widget.h"
#include "ui_widget.h"
#include <QByteArray>
#include <QBuffer> // 内存文件
#include <QDataStream>
#include <qDebug>
#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    
    QByteArray array;
    
    QBuffer memFile(&array);
    memFile.open(QIODevice::WriteOnly);
    memFile.write("1111111111111111111");
    memFile.write("2222222222222222222");
    
    memFile.close();
    cout << memFile.buffer();
    cout << "array" << array;
    
    
    QBuffer memFile1;
    memFile1.open(QIODevice::WriteOnly);
    QDataStream stream(&memFile1);
    
    stream << QString("测试") << 250;
    memFile1.close();
    cout << memFile1.buffer();
    
    memFile1.open(QIODevice::ReadOnly);
    QDataStream stream1;
    stream1.setDevice(&memFile1);
    QString str;
    int a;
    
    stream1 >> str >> a;
    memFile1.close();
    
    cout << str.toUtf8().data() << a;
}

Widget::~Widget()
{
    delete ui;
}
