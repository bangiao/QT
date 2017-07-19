#include "widget.h"
#include "ui_widget.h"
#include <QEvent>
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->installEventFilter(this);
    ui->label->setMouseTracking(true);
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->label)
    {
        QMouseEvent *env = static_cast<QMouseEvent *>(event);
        if (event->type() == QEvent::MouseMove)
        {
            ui->label->setText(QString("<center><h1>MouseMove: (%1, %2)</h1></center>").arg(env->x()).arg(env->y()));
            return true;
        }
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->label->setText(QString("<center><h1>MouseButtonPress: (%1, %2)</h1></center>").arg(env->x()).arg(env->y()));
            return true;
        }
        if (event->type() == QEvent::MouseButtonRelease)
        {
            ui->label->setText(QString("<center><h1>MouseButtonRelease: (%1, %2)</h1></center>").arg(env->x()).arg(env->y()));
            return true;
        }
    }
    return QWidget::eventFilter(watched, event);
}
