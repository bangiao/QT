#ifndef CHILDWIDGET_H
#define CHILDWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QString>

class ChildWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ChildWidget(QWidget *parent = 0);
    
signals:
    void sendsignals();
    void sendsignals(int num, QString);
public slots:
    
private:
    QPushButton button;
};

#endif // CHILDWIDGET_H
