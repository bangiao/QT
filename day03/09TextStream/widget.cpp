#include "widget.h"
#include "ui_widget.h"
#include <QTextStream>
#include <QFile>
#include <QFileDialog>
#include <qDebug>
#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    writeData();
    readData();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::writeData()
{
    QFile file;
    file.setFileName("demo.txt");
    bool isOk = file.open(QIODevice::ReadWrite);
    if (true == isOk)
    {
        // 这种格式取出来的对象写入 txt 中就是一个链接上去的文本 就是这样的
        // "主要看气质250" 全给他变成一个字符串 所以在取出字符串的时候
        // 会出现直接取出 "主要看气质250" 0 而不会是 主要看气质 250
        QTextStream stream(&file);
        //stream.setCodec("UTF-8");
        
        stream << QString("主要看气质") << 250;
    }
    file.close();
}

void Widget::readData()
{
    QFile file;
    file.setFileName("demo.txt");
    bool isOk = file.open(QIODevice::ReadOnly);
    if (true == isOk)
    {
        QTextStream stream(&file);
        QString str;
        int a;
        stream >> str >> a;
        cout << str << a;
    }
    file.close();
}

void Widget::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "open");
    if (false == path.isEmpty())
    {
        QFile file;
        file.setFileName("demo.txt");
        bool isOk = file.open(QIODevice::ReadOnly);
        if (true == isOk)
        {
            QTextStream stream(&file);
            
            // 指定编码
            // stream.setCodec("UTF-8");
            
            QString str = stream.readAll();
            ui->textEdit->setText(str);
        }
        file.close();
    }
}






