#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>
#include <qDebug>

#define cout (qDebug())

#define PORT 7777

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) 
{
    bool bRet = false;
    ui->setupUi(this);
    
    this->setWindowTitle(QString("窗口的端口号是: 7777"));
    
    this->m_udpSock = new QUdpSocket(this);
    // 绑定自己的ip和端口
    bRet = this->m_udpSock->bind(QHostAddress::AnyIPv4, PORT);
    if (false == bRet)
    {
        cout << "客户端绑定失败";
        throw -1;
    }
    
    // 加入组播
    bRet = this->m_udpSock->joinMulticastGroup(QHostAddress("224.0.0.2"));
    if (false == bRet)
    {
        cout << " fnc joinMulticastGroup err";
        throw 1;
    }
    // this->m_udpSock->leaveMulticastGroup(QHostAddress("224.0.0.2"));
    
    // 当对方发送数据过来
    // 自动触发 readyRead
    connect(this->m_udpSock, &QUdpSocket::readyRead, [=](){
        char bufdata[1024] = {0};
        
        QHostAddress client_addr;
        quint16 port;
        qint64 len = 0;
        qint64 ret = 0;
        while (1)
        {
            len = this->m_udpSock->pendingDatagramSize();
            if (-1 == len)
            {
                cout << "func err pendingDatagramSize";
                throw 2;
            }
            
            ret = this->m_udpSock->readDatagram(bufdata, len, &client_addr, &port);
            if (-1 == ret)
            {
                cout << "func err readDatagram";
                throw 3;
            }
            QString str = QString("[%1 : %2] %3").arg(client_addr.toString()).arg(port).arg(bufdata);
            ui->textEdit->setText(str);
            bool bRet = this->m_udpSock->hasPendingDatagrams() ;
            if (false == bRet)
            {
                break;
            }
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_send_pushButton_clicked()
{
    if (NULL != this->m_udpSock)
    {
        // 发送 的数据
        QString str = ui->textEdit->toPlainText();
        // 发送给谁
        // ip
        QHostAddress peer_addr(ui->ip_lineEdit->text()) ;
        // 端口
        quint16 port = ui->port_lineEdit_2->text().toInt();
        
        // 调用发送函数
        qint64 len = this->m_udpSock->writeDatagram(str.toStdString().c_str(), str.length(), peer_addr, port);
        if (-1 == len)
        {
            cout << "func err on_sendButton_clicked writeDatagram";
            return ;
        }
    }
}

void Widget::on_close_pushButton_2_clicked()
{
    // 关闭 sock 关键字
    this->m_udpSock->close();
    ui->textEdit->setText("关闭");
    this->close();
}
