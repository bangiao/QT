#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QUdpSocket>

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
    void on_sendButton_clicked();
    
    void on_closeButton_2_clicked();
    
private:
    Ui::ClientWidget *ui;
    QUdpSocket *m_udpSocket;
};

#endif // CLIENTWIDGET_H
