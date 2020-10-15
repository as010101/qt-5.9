#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QTreeWidget>
#include <QTableWidget>
#include <QStringListModel>
#include <QPushButton>
#include <thread>

void show1(QTableWidget *p,int row,QApplication *w)
{
       p->setItem(row, 1, new QTableWidgetItem(QString("xxx")));

}
void thread1(QTableWidget *p,QApplication *w)
{

    for (int i=0;i<5;i++)
        {

        show1(p,i,w);
        std::this_thread::sleep_for(std::chrono::seconds(1));
         w->processEvents();
    }

}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


   QTreeWidget * treeWidget = new QTreeWidget(&w);
       treeWidget->setColumnCount(1);
       QList<QTreeWidgetItem*> item;
       for(int i = 0; i < 3; i++)
       {
           item.append(new QTreeWidgetItem(treeWidget, QStringList(QString("itme :%1").arg(i))));
       }
       item.clear();
       for(int i = 0; i < 3; i++)
       {
           for(int j = 0; j < 3; j++)
               item.append(new QTreeWidgetItem(treeWidget->topLevelItem(i), QStringList(QString("item :%1%2").arg(i).arg(j))));
       }

       QTableWidget *tableWidget = new QTableWidget(&w);
       tableWidget->setColumnCount(5);
       tableWidget->setRowCount(5);

       QStringList tabeleHeader;
       tabeleHeader << "line Number" << "ID" << "Name" << "Age" << "Sex";
       tableWidget->setHorizontalHeaderLabels(tabeleHeader);
       tableWidget->setItem(0, 0, new QTableWidgetItem(QString("1")));
       tableWidget->setItem(1, 0, new QTableWidgetItem(QString("2")));
       tableWidget->setItem(2, 0, new QTableWidgetItem(QString("3")));
       tableWidget->setItem(3, 0, new QTableWidgetItem(QString("4")));
       tableWidget->setItem(4, 0, new QTableWidgetItem(QString("5")));
       tableWidget->setItem(0, 1, new QTableWidgetItem(QObject::tr("20100202")));

       QHBoxLayout *layou = new QHBoxLayout;
       layou->addWidget(treeWidget);
       layou->addWidget(tableWidget);



       QStringListModel *strModel = new QStringListModel(&w);
       QStringList strList;
       strList << "LetterA" << "LetterB" << "LetterC";
       strModel->setStringList(strList);
       QListView *listView = new QListView(&w);
       listView->setModel(strModel);

       QHBoxLayout *btnLayout = new QHBoxLayout;
       QPushButton *btnInsert = new QPushButton(QObject::tr("Insert"), &w); 
       QPushButton *btnDetele = new QPushButton(QObject::tr("Detele"), &w); 
      // QPushButton *btnShow = new QPushButton(QObject::tr("Show"), &w);
       btnLayout->addWidget(btnInsert); 
       btnLayout->addWidget(btnDetele);     
    //   btnLayout->addWidget(btnShow);

       QVBoxLayout *mianLayout = new QVBoxLayout(&w);   
       mianLayout->addLayout(layou);    
       mianLayout->addWidget(listView); 
       mianLayout->addLayout(btnLayout);    
      // setLayout(mianLayout);
    //layout->setVerticalSpacing(50);
    //layout->setHorizontalSpacing(80);
       mianLayout->setGeometry(QRect(500,500,500,500));
    w.centralWidget()->setLayout(mianLayout);
    w.show();
thread1(tableWidget,&a);
   // std::thread threadBegin(thread1,tableWidget,&a);   另起线程不能刷新的原因可能是 传入的a 对象已经消失了
    //threadBegin.join();
    //threadBegin.detach();
 //   std::this_thread::sleep_for(std::chrono::seconds(10));
    return a.exec();


}
