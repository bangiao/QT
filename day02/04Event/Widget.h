#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
    void keyPressEvent(QKeyEvent *ev);
    void timerEvent(QTimerEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *event);
    bool event(QEvent *event);
private:
    Ui::Widget *ui;
    int time_id;
};

#endif // WIDGET_H
