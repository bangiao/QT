#include "widget.h"
#include <QDateTime>
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QByteArray>
#include <QFileInfo>
#include <qDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_button_read_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "open", "../", "TXT(*.txt)");
    if (false == path.isEmpty())
    {
        // 文件对象
        QFile file(path);
        
        bool isOk = file.open(QIODevice::ReadOnly);
        if (true == isOk)
        {
#if 0
            // 读文件  默认只是别, utf8
            QByteArray array = file.readAll();
            // xianshi dao bianjikuang 
            ui->textEdit->setText(array);
#endif
            QByteArray array;
            while (false == file.atEnd())
            {
                // 度一行
                array += file.readLine();
            }
            ui->textEdit->setText(array);
        }
        file.close();
        
        // 获取文件信息
        QFileInfo info(path);
        
        qDebug() << "文件名字" << info.fileName().toLocal8Bit().data();
        qDebug() << "文件后缀" << info.suffix();
        qDebug() << "文件大小" << info.size();
        qDebug() << "文件创建时间" << info.created().toString("yyyy-MM-dd hh:mm:ss");
        
    }
}

void Widget::on_button_write_clicked()
{
    QString path = QFileDialog::getSaveFileName(this, "save", "../",
                                 "TEXT(*.txt)");
    if (false == path.isEmpty())
    {
        QFile file;
        file.setFileName(path);
        
         bool isOk = file.open(QIODevice::WriteOnly);
         if (true == isOk)
         {
             // 获取编辑区的内容
             QString str = ui->textEdit->toPlainText();
             
             // QString to QByteArray  只支持 UTF-8
             // file.write(str.toUtf8());
             
             // QString to string to char*  只支持 UTF-8
             //file.write(str.toStdString().data());
             
             // 转化成本地编码  系统是什么编码就是什么编码
             file.write(str.toLocal8Bit());
             
             // QByteArray to char *
             QByteArray array = "aaa";
             char * p_ch = array.data();
             
             // char * to QString
             char *p = "abc";
             QString c(p);
         }
         file.close();
    }
    
}
