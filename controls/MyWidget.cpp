#include "MyWidget.h"
// 文本编辑的空间
#include <QLabel>//静态文本框
#include <QLineEdit>
#include <QTextEdit>
#include <QTextBrowser>

#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QComboBox>
#include <QListWidget>
#include <QTreeWidget>
#include <QGroupBox>
#include <QSlider>
#include <QSpinBox>
#include <QProgressBar>
#include <QLCDNumber>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    //new QLabel("Label", this);
    
    //QLineEdit *lineEdit = new QLineEdit("LineEdit",  this);
   // lineEdit->setEchoMode(QLineEdit::Password);
    
    
    //QTextEdit *textedit = new QTextEdit("<h1>aaa</h1><h2>bbb</h2>", this);
    
    
    //QTextBrowser *textbrowser = new QTextBrowser("QTextBrowser", this);// 这个合适做报表
    
    //QRadioButton *radiobutton = new QRadioButton("QRadioButton", this);
    
   
    QCheckBox *checkbox = new QCheckBox("QCheckBox", this);
    checkbox->setGeometry(30, 30, 100, 30);
    QComboBox *combobox = new QComboBox(this);
    combobox->setGeometry(160, 30, 100, 30);
    combobox->addItem("aaa");
    combobox->addItem("bbb");
    combobox->addItem("ccc");    
    QListWidget *listwidget = new QListWidget(this);
    listwidget->setGeometry(290, 30, 100, 30);
    listwidget->addItem("ddd");
    listwidget->addItem("eee");
    listwidget->addItem("fff");
    
    QTreeWidget *treewidget = new QTreeWidget(this);
    treewidget->setGeometry(30, 90, 100, 30);
    QGroupBox *gruopbox = new QGroupBox("QGroupBox", this);
    gruopbox->setGeometry(160, 90, 100, 30);
    QSlider *slider = new QSlider(Qt::Orientation::Horizontal, this);
    slider->setGeometry(290, 90, 100, 30);
    
    QSpinBox *spinbox = new QSpinBox(this);
    spinbox->setGeometry(30, 120, 100, 30);
    QProgressBar *progressbar = new QProgressBar(this);
    progressbar->setGeometry(160, 120, 100, 30);
    // digi 设置数量, lcd的数量
    QLCDNumber *lcdnumber = new QLCDNumber(5, this);
    lcdnumber->display(55555);
    lcdnumber->setGeometry(290, 120, 100, 30);
}
