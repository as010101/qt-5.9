#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QPushButton *button = new QPushButton("Quit");
    QObject::connect(&w, SIGNAL(sig111x()), &w, SLOT(Message()));
    //QObject::connect(button, SIGNAL(clicked()), &w, SLOT(Message)); 有问题  声明中的slot不能去掉
    button->show();
   // qDebug()<<"out";
   // std::cout<<123<<std::endl;
    return a.exec();
}
