#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget (QWidget *parent = 0);
    ~Widget();
    
private slots:
    void on_send_pushButton_clicked();
    
    void on_close_pushButton_2_clicked();
    
private:
    Ui::Widget *ui;
    QUdpSocket *m_udpSock;
};

#endif // WIDGET_H
