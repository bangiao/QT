#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>

class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0);
    void setFlag(bool flag = true);
    
signals:
    // 向外部发送信号, 表示, 复杂数据执行完一次
    void mySignal();
    
public slots:
    void myTimerslots();
    
private:
    bool m_isStop;
};

#endif // MYTHREAD_H
