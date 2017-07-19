#include "widget.h"
#include <QDebug>
#include "ui_widget.h"
#include <QHostAddress>
#include <QFileDialog>
#include <QFileInfo>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_tcp_sock = NULL;
    this->setWindowTitle("Client");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_Connect_clicked()
{
    if (NULL == m_tcp_sock)
    {
        m_tcp_sock = new QTcpSocket(this);
        QHostAddress peer_addr(ui->lineEdit_ip->text());
        quint16 port = ui->lineEdit_port->text().toInt();
        m_tcp_sock->connectToHost(peer_addr, port);
        
        connect(&m_timer, &QTimer::timeout, [=](){
            m_timer.stop();
            SendData();
        });
    }
}

void Widget::on_pushButton_File_clicked()
{
    if (NULL == m_tcp_sock)
    {
        return ;
    }
    QString file_path = QFileDialog::getOpenFileName(this, "open", "../", "ALL(*.*)");
    if (true == file_path.isNull())
    {
        qDebug() << "未选择文件";
        return ;
    }
    
    qDebug() << file_path;
    
    QFileInfo info(file_path);
    m_file_size = info.size();
    m_file_name = info.fileName();
    m_file_cursize = 0;
    
    m_file.setFileName(file_path);
    bool isOk = m_file.open(QIODevice::ReadOnly);
    if (false == isOk)
    {
        qDebug() << "打开文件失败";
        return ;
    }
}

void Widget::on_pushButton_Send_clicked()
{
    if (NULL == m_tcp_sock)
    {
        return ;
    }
    
    QString head = QString("%1##%2").arg(m_file_size).arg(m_file_name);
    // 发送 头数据包
    // 发送的第一次的头数据包
    qint64 len = m_tcp_sock->write(head.toUtf8());
    if (len < 0)
    {
        qDebug() << "sock 发送失败";
        m_file.close();
        m_tcp_sock->disconnectFromHost();
        m_tcp_sock->close();
        return ;
    }
    m_timer.start(20);
    // 发送第二次数据包
}

void Widget::SendData()
{
    qint64 len = 0;
    do
    {
        char buf[4 * 1024] = {0};
        len = 0;
        
        len = m_file.read(buf, sizeof(buf));
        len = m_tcp_sock->write(buf, len);
        m_file_cursize += len;
    }while (len > 0);
    
    if (m_file_size == m_file_cursize)
    {
        setWindowTitle("文件发送完毕");
        m_file.close();
//        m_tcp_sock->disconnectFromHost();
//        m_tcp_sock->close();
    }
    time_handle = this->startTimer(1000);
}

void Widget::timerEvent(QTimerEvent *event)
{
    setWindowTitle("Client");
    this->killTimer(time_handle);
}
