#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QFile>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
    void SendData();
protected:
    void timerEvent(QTimerEvent *);
private slots:
    void on_pushButton_Connect_clicked();
    
    void on_pushButton_File_clicked();
    
    void on_pushButton_Send_clicked();
    
private:
    Ui::Widget *ui;
    QTcpSocket *m_tcp_sock;

    QFile m_file;
    
    qint64 m_file_size;
    qint64 m_file_cursize;
    QString m_file_name;
    
    QTimer m_timer;

    int time_handle;
};

#endif // WIDGET_H
