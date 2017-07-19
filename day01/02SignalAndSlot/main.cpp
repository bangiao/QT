#include <QApplication>
#include "mywidget.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    mywidget w;
    
    w.show();
    app.exec();
    return 0;
}
