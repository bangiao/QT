#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class ClientWidget;
}

class ClientWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit ClientWidget(QWidget *parent = 0);
    ~ClientWidget();
    
private slots:
    void on_connectButton_clicked();
    
    void on_send_pushButton_clicked();
    
    void on_pushButton_clicked();
protected:
    void timerEvent(QTimerEvent *event);
    
private:
    Ui::ClientWidget *ui;
    QTcpSocket *m_tcpSock;
    int time_handle;
};

#endif // CLIENTWIDGET_H
