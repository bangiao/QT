#include "widget.h"
#include "ui_widget.h"
#include <QDataStream>
#include <QFile>
#include <qDebug>
#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    writeData();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::writeData()
{
    QFile file("test.txt");
    
    bool isOk = file.open(QIODevice::WriteOnly);
    if (true == isOk)
    {
        // 创建数据流 和file 文件关联
        //  往数据流中输入(写)数据, 相于往文件里写数据
        QDataStream stream(&file);
        stream << QString("主要看气质") << 250;
        file.close();
    }
}

void Widget::readData()
{
    QFile file("test.txt");
    
    bool isOk = file.open(QIODevice::ReadOnly);
    if (true == isOk)
    {
        // 创建数据流 和file 文件关联
        //  往数据流中输出(读)数据, 相于往文件里读数据
        QDataStream stream(&file);
        // 读的时候以写的顺序执行, 去取数据
        QString str;
        int a;
        
        stream >> str >> a;
        
        // qDebug() << str << a;
        cout << str << a;
        
        file.close();
    }
}

void Widget::on_pushButton_clicked()
{
    readData();
}
