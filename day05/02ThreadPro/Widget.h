#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "MyThread.h"
#include <QThread>
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
    
    void dealSignal();
signals:
    // 开始线程信号
    void startTread_Signal();
    
private slots:
    void on_pushButton_clicked();
    
    void on_pushButton_2_clicked();
    
private:
    Ui::Widget *ui;
    MyThread *m_myThread;
    QThread *m_thread;
};

#endif // WIDGET_H
