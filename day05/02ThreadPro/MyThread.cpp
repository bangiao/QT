#include "MyThread.h"
#include <QDebug>
#include <QThread>

MyThread::MyThread(QObject *parent) : QObject(parent)
{
    m_isStop = false;
    
}

void MyThread::setFlag(bool flag)
{
    m_isStop = flag;
}

void MyThread::myTimerslots()
{
    while (m_isStop == false) 
    {
        // 执行很复杂的操作
        QThread::sleep(1);
        qDebug() << "子线程的 ID: " << QThread::currentThread();
        // 没一秒向外部发送信号
        emit mySignal();
        if (true == m_isStop)
        {
            break;
        }
    }
}
