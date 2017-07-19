#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QTimer>
#include <QTimerEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
protected:
    void timerEvent(QTimerEvent *event);
    
private:
    Ui::Widget *ui;
    
    QTcpServer *m_tcp_Server;
    QTcpSocket *m_tcp_Sock;
    
    QFile m_file;
    
    QString m_data_path; // 包发送的名字
    qint64 m_data_len; // 包发送过来的长度
    qint64 m_data_curlen; // 包的当前长度
    
    bool m_isStart; // 是不是第一次发送这个数据包
    bool m_newLink;
    
    QTimer m_timer;
};

#endif // WIDGET_H
