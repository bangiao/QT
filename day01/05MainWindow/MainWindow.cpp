#include "MainWindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <qDebug>
#include <QMessageBox>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(400, 300);
    
    // 菜单栏
    QMenuBar *m_wndBar = menuBar();
    // 添加菜单
    QMenu *pFile = m_wndBar->addMenu("文件");
    // 添加菜单项, 添加动作
    QAction *pNew  = pFile->addAction("新建");
    
    connect(pNew, &QAction::triggered, this, [=]()
    {
        qDebug() << "新建";
    });
    pFile->addSeparator();//添加分割线
    
    QAction *pOpen = pFile->addAction("打开");
    connect(pOpen, &QAction::triggered, this, [=](){
        qDebug() << "打开";
    });
    
    // 工具栏
    QToolBar *m_wndToolBar = addToolBar(QString("toolbar"));
    
    // 工具栏添加快捷键
    m_wndToolBar->addAction(pNew);
    QPushButton *b = new QPushButton(this);
    b->setText("^_^");
    // 添加小控件
    m_wndToolBar->addWidget(b);
    connect(b, QPushButton::clicked, [=](){
        qDebug() << "按下按钮";
        b->setText("@_@");
    });
    
    // 状态栏
    QStatusBar *m_wndStatusBar = statusBar();
    QLabel *m_wndLabel = new QLabel(this);
    m_wndLabel->setText("Normal text file");
    m_wndStatusBar->addWidget(m_wndLabel);
    m_wndStatusBar->addWidget(new QLabel("2", this));
    m_wndStatusBar->addPermanentWidget(new QLabel("3", this));
    
    // 核心控件
    QTextEdit *m_wndTextEdit = new QTextEdit(this);
    setCentralWidget(m_wndTextEdit);
    
    // 浮动窗口
    
    QDockWidget *m_wndDock = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea, m_wndDock);

    // 给浮动窗口添加控件
    QTextEdit *m_wndTextEdit1 = new QTextEdit(this);
    m_wndDock->setWidget(m_wndTextEdit1);
    
}

MainWindow::~MainWindow()
{
    
}
