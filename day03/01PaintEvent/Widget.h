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
    void paintEvent(QPaintEvent *event);
    
private slots:
    void on_pushButton_clicked();
    
private:
    int x;
    int pic_width;
    Ui::Widget *ui;
};

#endif // WIDGET_H
