#include "MainWindow.h"
#include "ui_mainwindow.h"
// #include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    ui->label->setStyleSheet("QLabel{color:rgb(0, 255, 255);"
                             "background-color:blue;"
                             "background-image:url(:/new/prefix1/resource/1_144051L04.jpg)"
                             "}");
    
    ui->label_2->setStyleSheet("QLabel{color:rgb(0, 255, 255);"
                               "border-width:4px;"
                               "border-image:url(:/new/prefix1/resource/21-080826_12.jpg) 5 5 5 5 stretch stretch;"
                               "}");
    
    ui->pushButton->setStyleSheet("QPushButton{"
                                  " border:2px outset green;"
                                  " }"
                                  "QPushButton:hover {"
                                  "border-image:url(:/new/prefix1/resource/21-080826_12.jpg) "
                                  "}"
                                  "QPushButton:pressed {"
                                  "border-image:url(:/new/prefix1/resource/2013073113.jpeg) "
                                  "}"
                                  );
    
    ui->pushButton_2->setStyleSheet("QPushButton {"
                                    "border:2px outset green;"
                                    "border-radius: 10px;"
                                    "background-image:url(:/new/prefix1/resource/2013073113.jpeg);"
                                    "font: bold 14px;"
                                    "min-width: 10em;"
                                    "padding: 6px;"
                                    "}"
                                    "QPushButton:pressed {"
                                    "border-image:url(:/new/prefix1/resource/21-080826_12.jpg)"
                                    "}");
}

MainWindow::~MainWindow()
{
    delete ui;
}
