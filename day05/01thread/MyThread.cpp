#include "MyThread.h"

MyThread::MyThread(QObject *parent) : QThread(parent)// 这里的 QObject 需要改成 QThread 给基类构造函数传递参数
{
    
}

void MyThread::run()
{
    // 很复杂的数据处理 需要耗时 5 秒
    sleep(5);
    emit isDoneSignal();// 发送信号
}
