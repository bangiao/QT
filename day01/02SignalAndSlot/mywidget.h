#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "childwidget.h"
#include <QPushButton>

class mywidget : public QWidget
{
    Q_OBJECT
public:
    explicit mywidget(QWidget *parent = 0);
    
signals:
    
public slots:
    void create_child_slot();
    void create_parent_slot();
private:
    childwidget w;
   QPushButton b;
};

#endif // MYWIDGET_H
