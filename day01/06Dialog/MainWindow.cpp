#include "MainWindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(400, 300);
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);
    QMenu *menu = mBar->addMenu("对话框");
    QAction *p1 = menu->addAction("模态对话框");
    connect(p1, &QAction::triggered, [=](){
        QDialog dlg1;
        dlg1.resize(400, 300);
        dlg1.exec();
    });
    
    QAction *p2 = menu->addAction("非模态对话框");
    connect(p2, &QAction::triggered, [=](){
        // 这样的话, 内存会越用月小
        QDialog *dlg = new QDialog(this);
        dlg->resize(400, 300);
        dlg->setAttribute(Qt::WA_DeleteOnClose);
        dlg->show();
//        dlg.resize(400, 300);
//        dlg.show();
    });
    
    QAction *p3 = menu->addAction(" 关于对话框");
    connect(p3, &QAction::triggered, [=](){
       QMessageBox::about(this, "about", "关于qt");
    });
    
    QAction *p4 = menu->addAction(" 问题对话框");
    connect(p4, &QAction::triggered, [=](){
       int ret = QMessageBox::question(this, "question", "Are you ok?");
       switch(ret)
       {
       case QMessageBox::Yes:
           qDebug() << "I am ok";
           break;
       case QMessageBox::No:
           qDebug() << "I am bad";
           break;
       default:
           break;
       }
    });
    
    QAction *p5 = menu->addAction("文件对话框");
    connect(p5, &QAction::triggered, [=](){
       QString path = QFileDialog::getOpenFileName(this, QString("Open File"), QString("../"), 
                                                  tr("image (*.png *.xpm *.jpg *.*);;"
                                                     "text(*.txt *.doc *.docx *.*)"));
       qDebug() << path;
    });
    
}

MainWindow::~MainWindow()
{
    
}
