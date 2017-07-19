#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    
    // 打印 qt 支持的数据库驱动
    qDebug () << QSqlDatabase::drivers();
    
    // 添加数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    // 连接数据库
    db.setHostName("127.0.0.1");
    db.setUserName("root");//数据库用户名
    db.setPassword("a2264426");// 数据库密码
    db.setDatabaseName("sys");// 使用哪个数据库
    
    QStringList drivers=QSqlDatabase::drivers();
    const int c=drivers.count();
    
    // 打开数据库
    if (false == db.open())
    {
        QMessageBox::warning(this, "错误", db.lastError().text());
        return ;
    }
    
}

Widget::~Widget()
{
    delete ui;
}
