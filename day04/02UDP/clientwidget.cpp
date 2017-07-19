#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QHostAddress>
#include <qDebug>

#define PORT 9999

#define cout (qDebug())

/*
    // 结束
*/

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("本程序的端口号: 9999");
    
    // 创建 udp 对象, 绑定 对应的ip 和端口  
    this->m_udpSocket = new QUdpSocket(this);
    bool bRet = this->m_udpSocket->bind(QHostAddress::AnyIPv4, PORT);
    if (false == bRet)
    {
        cout << "func err bind";
        throw -1;
    }
    
    // 加入组播 
    bRet = this->m_udpSocket->joinMulticastGroup(QHostAddress("224.0.0.2"));
    if (false == bRet)
    {
        cout << " fnc joinMulticastGroup err";
        throw 1;
    }
    // this->m_udpSocket->leaveMulticastGroup(QHostAddress("224.0.0.2"));
    
    // 监控数据的接收
    // 接收
    connect(this->m_udpSocket, &QUdpSocket::readyRead, [=](){
        char buf[1024] = {0};
        qint64 len = 0;
        QHostAddress peer_addr;
        quint16 port;
        qint64 ret;
        bool bRet = false;
        
        while (1)
        {
            len = this->m_udpSocket->pendingDatagramSize();
            if (-1 == len)
            {
                cout << "func err readDatagram";
                throw -3;
            }
            
            ret = this->m_udpSocket->readDatagram(buf, len, &peer_addr, &port);
            if (-1 == ret)
            {
                cout << "func err readDatagram";
                throw -4;
            }
            QString str = QString("[%1 : %2] %3").arg(peer_addr.toString()).arg(port).arg(buf);
            ui->textEdit->setText(str);
            bRet = this->m_udpSocket->hasPendingDatagrams();
            if (false == bRet)
            {
                break;
            }
        }
        
    });
    
    
}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_sendButton_clicked()
{
    if (NULL != this->m_udpSocket)
    {
        // 发送 的数据
        QString str = ui->textEdit->toPlainText();
        // 发送给谁
        // ip
        QHostAddress peer_addr(ui->ip_lineEdit->text()) ;
        // 端口
        quint16 port = ui->port_lineEdit_2->text().toInt();
        
        // 调用发送函数
        qint64 len = this->m_udpSocket->writeDatagram(str.toStdString().c_str(), str.length(), peer_addr, port);
        if (-1 == len)
        {
            cout << "func err on_sendButton_clicked writeDatagram";
            return ;
        }
    }
}
// 结束
void ClientWidget::on_closeButton_2_clicked()
{
    if (NULL != this->m_udpSocket)
    {
        this->m_udpSocket->close();
    }
    this->close();
}
