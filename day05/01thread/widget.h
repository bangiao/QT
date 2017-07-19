#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include "MyThread.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
public slots:
    void dealTimeOut();
protected slots:
    void dealDoneSignal();
    void stopThread();
private slots:
    void on_pushButton_clicked();
    
private:
    Ui::Widget *ui;
    QTimer *m_timer;
    MyThread *m_thread;
};

#endif // WIDGET_H
