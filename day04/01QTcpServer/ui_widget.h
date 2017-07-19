/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QTextEdit *read_Text;
    QTextEdit *write_Text;
    QPushButton *But_send;
    QSpacerItem *horizontalSpacer;
    QPushButton *But_close;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        read_Text = new QTextEdit(Widget);
        read_Text->setObjectName(QStringLiteral("read_Text"));
        read_Text->setReadOnly(true);

        gridLayout->addWidget(read_Text, 0, 0, 1, 3);

        write_Text = new QTextEdit(Widget);
        write_Text->setObjectName(QStringLiteral("write_Text"));

        gridLayout->addWidget(write_Text, 1, 0, 1, 3);

        But_send = new QPushButton(Widget);
        But_send->setObjectName(QStringLiteral("But_send"));

        gridLayout->addWidget(But_send, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(217, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        But_close = new QPushButton(Widget);
        But_close->setObjectName(QStringLiteral("But_close"));

        gridLayout->addWidget(But_close, 2, 2, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        But_send->setText(QApplication::translate("Widget", "send", Q_NULLPTR));
        But_close->setText(QApplication::translate("Widget", "close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
