#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    
    Widget(QWidget *parent = 0);
    ~Widget();
    
    void drawGrid();
    
    void paintEvent(QPaintEvent *event);
    void PointToPosition();
protected:
    void mousePressEvent(QMouseEvent *event);
    
private:
    int start_x;
    int start_y;
    int grid_x;
    int grid_y;
    int x;
    int y;
};

#endif // WIDGET_H
