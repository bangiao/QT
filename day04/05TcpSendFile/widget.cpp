#include "widget.h"
#include "ui_widget.h"
#include <QByteArray>
#include <QHostAddress>

#define PORT 8888

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    
    m_tcp_Server = NULL;
    m_tcp_Sock = NULL;
    
    this->startTimer(1000); // 要启动这个时间事件的话, 那么要考虑   m_tcp_Sock = NULL;
    
    // 设置进度条的 range
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);
    
    m_tcp_Server = new QTcpServer(this);
    
    m_tcp_Server->listen(QHostAddress::AnyIPv4, PORT);
    
    setWindowTitle("客户端未连接...");
    
    // 新连接连接上
    connect(m_tcp_Server, &QTcpServer::newConnection, [=](){
        // 从内核中取出 我们已经连接上的连接数据
        m_tcp_Sock = m_tcp_Server->nextPendingConnection();
        if (0 == m_tcp_Sock)
        {
            qDebug() << "func err nextPendingConnection";
            return ;
        }
        m_newLink = true; // you lian jie lian shang
        
        // 获取客户端的 ip 和 端口
        QHostAddress peer_addr = m_tcp_Sock->peerAddress();
        if (QHostAddress::Null == peer_addr)
        {
            qDebug() << "func err peerAddress";
            return ;
        }
        quint16 peer_port = m_tcp_Sock->peerPort();
        if (0 == peer_port)
        {
            qDebug() << "func err peerPort";
            return ;
        }
        
        setWindowTitle(QString("客户端连接上  ip: %1, port: %2").arg(peer_addr.toString()).arg(peer_port));
        
        // 有新的数据到来
        connect(m_tcp_Sock, &QTcpSocket::readyRead, [=](){
            // 这个包 分两次收,
            
            QByteArray arr;
            
            // 接收数据包的内容
            if (m_tcp_Sock != NULL)
            {
                arr = m_tcp_Sock->readAll();
                if (arr.isEmpty())
                {
                    qDebug() << "func err readAll";
                    return ;
                }
            }
                
            
            // 第一次是 包的长度和包的名字
            if (true == m_isStart)
            {
                // 长度##包名
                
                // 获取文件的长度
                m_data_len = QString(arr).section("##", 0, 0).toInt();
                // 获取文件的名字
                m_data_path = QString(arr).section("##", 1, 1);
                m_data_curlen = 0;
                
                // 设置进度条的初始位置
                if (m_data_len != 0)
                    ui->progressBar->setValue((m_data_curlen / m_data_len) * ui->progressBar->maximum());
                
                
                m_file.setFileName(m_data_path);
                // 打开文件
                bool isOk = m_file.open(QIODevice::WriteOnly);
                if (false == isOk)
                {
                    qDebug() << "文件打开失败";
                    throw 1;
                }
                m_isStart = false;
            }
            else // 第二次是 包的内容
            {
                m_data_curlen = 0;
                const char *p_arr = arr.toStdString().c_str();
                // 将第二次接收到的数据包加入到文件中
                qint64 len = 0;
                do
                {
                    if (m_data_len != 0)
                        ui->progressBar->setValue((m_data_curlen / m_data_len) * ui->progressBar->maximum());
                    len = m_file.write(p_arr);
                    if (-1 == len)
                    {
                        qDebug() << "文件写入失败";
                        throw 2;
                    }
                    p_arr += len;
                    m_data_curlen += len;
                    if (m_data_curlen >= m_data_len)// fa song wan bi
                    {
                        if (NULL != m_tcp_Sock)
                        {
                            m_file.close();
//                            m_tcp_Sock->disconnectFromHost();
//                            m_tcp_Sock->close();
//                            m_tcp_Sock = NULL;
                        }
                        break;
                    }
                }while (*p_arr != '\0');
                m_isStart = true;
            }
        });
    });
    
    
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    if (NULL == m_tcp_Sock)
    {
        return ;
    }
    if (m_tcp_Sock->state() == QAbstractSocket::UnconnectedState)
    {
        if (true == m_newLink)
        {
            if (NULL != m_tcp_Sock)
            {
                m_tcp_Sock->disconnectFromHost();
                m_tcp_Sock->close();
                this->setWindowTitle("客户端关闭...");
                m_tcp_Sock = NULL;
            }
            m_newLink = false;
        }
    }
}
