#ifndef CHILDWIDGET_H
#define CHILDWIDGET_H

#include <QWidget>
#include <QPushButton>

class childwidget : public QWidget
{
    Q_OBJECT
public:
    explicit childwidget(QWidget *parent = 0);
signals:
    void sendsignals();
public slots:
    void myslot();
private:
    QPushButton b;
};

#endif // CHILDWIDGET_H
