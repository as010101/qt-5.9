#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // QLabel *l=new QLabel();
   //        l= ui->label_5;
  //         l->setText("xxxx");


           QGridLayout *glay = new QGridLayout();
              glay->setSpacing(0);
              glay->setMargin(0);
              glay->setHorizontalSpacing(0);
              glay->setVerticalSpacing(0);
              glay->setContentsMargins(0,0,0,0);
              QPushButton *bt1 = new QPushButton("pushButton00");
              QPushButton *bt2 = new QPushButton("pushButton10");
              QPushButton *bt3 = new QPushButton("pushButton20");
              QPushButton *bt4 = new QPushButton("pushButton01");
              QPushButton *bt5 = new QPushButton("pushButton21");


              glay->addWidget(bt1,0,0);
              glay->addWidget(bt2,1,0);
              glay->addWidget(bt3,2,0);

              glay->addWidget(bt4,0,1);
              glay->addWidget(bt5,2,1);



              ui->scrollArea_2->widget()->setLayout(glay);//把布局放置到QScrollArea的内部QWidget中

}

MainWindow::~MainWindow()
{
    delete ui;
}

