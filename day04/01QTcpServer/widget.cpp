#include "widget.h"
#include "ui_widget.h"
#include <QTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->m_tcpServer = NULL;
    this->m_tcpSock = NULL;
    setWindowTitle("服务端:8888");
    // 监听套接字, 指定父对象, 让其自动回收
    this->m_tcpServer = new QTcpServer(this);
    
    this->startTimer(2000);
    
    m_tcpServer->listen(QHostAddress::Any, 8888);
    
    //  监控服务端是否收到信号 newConnection 收到代表有新的连接连接
    connect(this->m_tcpServer, &QTcpServer::newConnection, 
            [=](){
        // 去取出建立好的连接  只有这个 nextPendingConnection 函数返回 QTcpSocket 类型
        this->m_tcpSock = this->m_tcpServer->nextPendingConnection();
        
        // 获取对方的 IP 和 端口
        QString ip = this->m_tcpSock->peerAddress().toString();
        qint16 port = this->m_tcpSock->peerPort();
        QString tmp = QString("[%1:%2]:成功连接").arg(ip).arg(port);
        ui->read_Text->setText(tmp);
        
        // 监控信号 readyRead 判断时候有新的接收
        // 这段代码必须写在这里面, 因为这个 this->m_tcpSock 只有在这个 lamdba 语句中才有值
        // 或者说在 lmadba 语句中才绝对会有值
        connect(this->m_tcpSock, &QTcpSocket::readyRead, 
                [=](){
            // 从通信套接字中取出内容
            QByteArray arr = this->m_tcpSock->readAll();
            ui->read_Text->append(arr.data());
        });
        
        // 对端关闭
//        connect(this->m_tcpSock, &QTcpSocket::connected, [=](){
//            ui->read_Text->append(QString("关闭"));
//        });
    });   
}

Widget::~Widget()
{
    if (NULL != this->m_tcpSock)
    {
        this->m_tcpSock->close();
        this->m_tcpSock = NULL;
    }
    delete ui;
}

void Widget::on_But_send_clicked()
{
    if (NULL == this->m_tcpSock)
    {
        return ;
    }
    // 获取编辑区的内容
    QString str = ui->write_Text->toPlainText();
    // 给对方发送数据 使用套接字 发送
    this->m_tcpSock->write(str.toUtf8().data());
    ui->write_Text->setText("");
}

void Widget::on_But_close_clicked()
{
    if (NULL == this->m_tcpSock)
    {
        return ;
    }
    // 主动和客户端端口关闭来连接
    this->m_tcpSock->disconnectFromHost();
    this->m_tcpSock->close();
    this->m_tcpSock = NULL;
    ui->read_Text->append(QString("关闭"));
}

void Widget::timerEvent(QTimerEvent *event)
{
    if (NULL != this->m_tcpSock)
    {
        int ret = this->m_tcpSock->state();
        if (QAbstractSocket::UnconnectedState == ret)
        {
            ui->read_Text->append("客户端关闭");
            if (NULL != this->m_tcpSock)
            {
                this->m_tcpSock->disconnectFromHost();
                this->m_tcpSock->close();
                this->m_tcpSock = NULL;
            }
        }
    }
    event->accept();
}
