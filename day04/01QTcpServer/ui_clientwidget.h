/********************************************************************************
** Form generated from reading UI file 'clientwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWIDGET_H
#define UI_CLIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *port_label;
    QLineEdit *port_lineEdit;
    QPushButton *connectButton;
    QLabel *ip_label;
    QLineEdit *ipLineEdit;
    QTextEdit *readtextEdit;
    QTextEdit *wirtetextEdit;
    QPushButton *send_pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *ClientWidget)
    {
        if (ClientWidget->objectName().isEmpty())
            ClientWidget->setObjectName(QStringLiteral("ClientWidget"));
        ClientWidget->resize(400, 300);
        gridLayout = new QGridLayout(ClientWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        port_label = new QLabel(ClientWidget);
        port_label->setObjectName(QStringLiteral("port_label"));

        gridLayout->addWidget(port_label, 0, 0, 1, 1);

        port_lineEdit = new QLineEdit(ClientWidget);
        port_lineEdit->setObjectName(QStringLiteral("port_lineEdit"));

        gridLayout->addWidget(port_lineEdit, 0, 1, 1, 3);

        connectButton = new QPushButton(ClientWidget);
        connectButton->setObjectName(QStringLiteral("connectButton"));

        gridLayout->addWidget(connectButton, 0, 4, 2, 1);

        ip_label = new QLabel(ClientWidget);
        ip_label->setObjectName(QStringLiteral("ip_label"));

        gridLayout->addWidget(ip_label, 1, 0, 1, 1);

        ipLineEdit = new QLineEdit(ClientWidget);
        ipLineEdit->setObjectName(QStringLiteral("ipLineEdit"));

        gridLayout->addWidget(ipLineEdit, 1, 1, 1, 3);

        readtextEdit = new QTextEdit(ClientWidget);
        readtextEdit->setObjectName(QStringLiteral("readtextEdit"));
        readtextEdit->setReadOnly(true);

        gridLayout->addWidget(readtextEdit, 2, 0, 1, 5);

        wirtetextEdit = new QTextEdit(ClientWidget);
        wirtetextEdit->setObjectName(QStringLiteral("wirtetextEdit"));

        gridLayout->addWidget(wirtetextEdit, 3, 0, 1, 5);

        send_pushButton = new QPushButton(ClientWidget);
        send_pushButton->setObjectName(QStringLiteral("send_pushButton"));

        gridLayout->addWidget(send_pushButton, 4, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(211, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 2, 1, 1);

        pushButton = new QPushButton(ClientWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 4, 3, 1, 2);


        retranslateUi(ClientWidget);

        QMetaObject::connectSlotsByName(ClientWidget);
    } // setupUi

    void retranslateUi(QWidget *ClientWidget)
    {
        ClientWidget->setWindowTitle(QApplication::translate("ClientWidget", "Form", Q_NULLPTR));
        port_label->setText(QApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243:", Q_NULLPTR));
        port_lineEdit->setText(QApplication::translate("ClientWidget", "8888", Q_NULLPTR));
        connectButton->setText(QApplication::translate("ClientWidget", "connect", Q_NULLPTR));
        ip_label->setText(QApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250ip:", Q_NULLPTR));
        ipLineEdit->setText(QApplication::translate("ClientWidget", "127.0.0.1", Q_NULLPTR));
        send_pushButton->setText(QApplication::translate("ClientWidget", "send", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ClientWidget", "close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ClientWidget: public Ui_ClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H
