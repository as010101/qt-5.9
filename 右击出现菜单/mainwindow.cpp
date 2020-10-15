#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    addAction(new   QAction("一",this));
//     addAction(new   QAction("二",this));
//      addAction(new   QAction("三",this));
//      setContextMenuPolicy(Qt::ActionsContextMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::contextMenuEvent(QContextMenuEvent *event)
//{}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu *menu=new QMenu(this);
    menu->addAction(new   QAction("一",this));
    menu->addAction(new   QAction("二",this));
    menu->addAction(new   QAction("s",this));
    menu->move(cursor().pos());
    menu->show();
}
