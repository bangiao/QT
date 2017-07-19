#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QHostAddress>

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("客户端");
    this->m_tcpSock = NULL;
    
    this->time_handle = this->startTimer(2000);
    
    
    
}

ClientWidget::~ClientWidget()
{
    if (NULL != this->m_tcpSock)
    {
        this->m_tcpSock->close();
        this->m_tcpSock = NULL;
    }
    delete ui;
}

void ClientWidget::on_connectButton_clicked()
{
    if (NULL == this->m_tcpSock)
    {
        // 分配空间指定父对象
        this->m_tcpSock = new QTcpSocket(this);
        
        // panduan chenggong lianjie 
        connect(this->m_tcpSock, &QTcpSocket::connected, [=](){
            ui->readtextEdit->setText("成功和服务器建立连接");
        });
        
        // du shuju 
        connect(this->m_tcpSock, &QTcpSocket::readyRead, [=](){
            QByteArray arr = this->m_tcpSock->readAll();
            ui->readtextEdit->append(arr.data());
        });
        
        
        // 关闭
//        connect(this->m_tcpSock, &QTcpSocket::disconnected, [=](){
//            ui->readtextEdit->append(QString("关闭"));
//            this->m_tcpSock->disconnectFromHost();
//        });
        
        // huoqu fuwuqi ip duankou 
        QString ip = ui->ipLineEdit->text();
        qint16 port = ui->port_lineEdit->text().toInt();
        
        // 主动和服务器建立连接
        this->m_tcpSock->connectToHost(QHostAddress(ip), port);
    }
}

void ClientWidget::on_send_pushButton_clicked()
{
    if (NULL != this->m_tcpSock)
    {
        // huoqu bianjiluang de neirong 
        QString str = ui->wirtetextEdit->toPlainText();
        // fasong shuju
        this->m_tcpSock->write(str.toUtf8().data());
        ui->wirtetextEdit->setText("");
    }
}

void ClientWidget::on_pushButton_clicked()
{
    if (NULL != this->m_tcpSock)
    {
        this->m_tcpSock->disconnectFromHost();
        this->m_tcpSock->close();
        this->m_tcpSock = NULL;
        ui->readtextEdit->append(QString("关闭"));
    }
}

void ClientWidget::timerEvent(QTimerEvent *event)
{
    if (NULL != this->m_tcpSock)
    {
        int ret = this->m_tcpSock->state();
        if (QAbstractSocket::UnconnectedState == ret)
        {
            ui->readtextEdit->append("服务端关闭");
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
