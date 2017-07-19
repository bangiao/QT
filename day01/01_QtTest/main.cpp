#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // 程序应用类, 主要是接受处理事件 的
    QApplication a(argc, argv);
    // 窗口类
    Widget w;
    w.show();
    // 死循环, 等待事件的发生
    return a.exec();
}
