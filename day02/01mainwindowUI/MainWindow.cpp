#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <QCompleter>
#include <QStringList>
#include <QMovie>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("close");
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::close);
    connect(ui->actionclose, &QAction::triggered, this, &MainWindow::close);
    
    
    // 编辑框提示案例
    QStringList list;
    
    list << "zhazha" << "2033445917" << "Helloworld";
    QCompleter *pCom = new QCompleter(list, this);
    pCom->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(pCom);
    
    // 密码显示
    // ui->lineEdit->setEchoMode(QLineEdit::Password);
    
    // QLabel 
    ui->label_text->setText("<h1>zhazha</h1>");
    
    // QLabel pic
    ui->label_pic->setPixmap(QPixmap("://resource/_1.jpg"));
    //ui->label_pic->setPixmap(QPixmap("://resource/_2.gif"));
    ui->label_pic->setScaledContents(true);
    
    // QLabel gif
    QMovie *pMov = new QMovie(QString("://resource/_2.gif"));
    ui->label_gif->setMovie(pMov);
    // ui->label_gif->setScaledContents(true);
    pMov->start();
    
    // QLabel url
    ui->label_url->setText("<a target=\"_blank\" href=\"https://www.baidu.com\">https://www.baidu.com</a>");
    ui->label_url->setScaledContents(true);
    ui->label_url->setOpenExternalLinks(true);
    
    // 数码管
    ui->lcdNumber->display(123.3);
    
    // 进度条
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(200);
    ui->progressBar->setValue(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_nextBut_clicked()
{
    // UI 设置槽函数案例
    static int i = 0;
    ui->stackedWidget->setCurrentIndex(++i % 4);
}
