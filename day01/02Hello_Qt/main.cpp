#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget w;
    w.setWindowTitle("zhazha");
    w.show();
    
    QPushButton p1;
    p1.setText("haha");
    p1.setParent(&w);
    p1.show();
    p1.move(100, 100);
    
    QPushButton p2(&w);
    p2.setText("p2 zhazha");
    p2.show();
    
    return app.exec();
}
