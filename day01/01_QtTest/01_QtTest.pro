#-------------------------------------------------
#
# Project created by QtCreator 2017-04-04T11:31:38
#
#-------------------------------------------------

#模块
QT       += core gui
#高于4版本, 向 4 版本兼容
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#应用程序名字
TARGET = 01_QtTest
#指定makefile 的类型, Makefile app  .a .so
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# 源文件
SOURCES += main.cpp\
        widget.cpp
#  头文件
HEADERS  += widget.h
