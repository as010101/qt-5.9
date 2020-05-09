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
           QGridLayout *pLayout = new QGridLayout();//网格布局
              for(int i = 0; i < 100; i++)
              {
                  QPushButton *pBtn = new QPushButton();
                  pBtn->setText(QString("按钮%1").arg(i));
                  pBtn->setMinimumSize(QSize(60,30));   //width height
                  pLayout->addWidget(pBtn);//把按钮添加到布局控件中
              }
              ui->scrollArea_2->widget()->setLayout(pLayout);//把布局放置到QScrollArea的内部QWidget中

}

MainWindow::~MainWindow()
{
    delete ui;
}

