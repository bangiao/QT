#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>//监听套接字
#include <QTcpSocket>//通信套接字

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private slots:
    void on_But_send_clicked();
    void on_But_close_clicked();
protected:
    void timerEvent(QTimerEvent *event);
    
private:
    Ui::Widget *ui;
    QTcpServer *m_tcpServer;
    QTcpSocket *m_tcpSock;
    int time_handle;
};

#endif // WIDGET_H
