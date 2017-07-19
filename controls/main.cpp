#include <QApplication>
#include "MyWidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWidget w;
    w.show();
    w.setGeometry(200, 200, 500, 300);
    return app.exec();
}
