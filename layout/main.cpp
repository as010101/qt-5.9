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
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

//    QGridLayout *layout = new QGridLayout;

//        QLabel *label1 = new QLabel("Font");
//        QLabel *label2 = new QLabel("Font style");
//        QLabel *label3 = new QLabel("Size");

//        QLineEdit *lineEdit1 = new QLineEdit;
//        QLineEdit *lineEdit2 = new QLineEdit;
//        QLineEdit *lineEdit3 = new QLineEdit;

//        QListWidget *list1 = new QListWidget;
//        QListWidget *list2 = new QListWidget;
//        QListWidget *list3 = new QListWidget;

//        layout->addWidget(label1, 1, 1);
//        layout->addWidget(label2, 1, 3);
//        layout->addWidget(label3, 1, 5);

//        layout->addWidget(lineEdit1, 2, 1);
//        layout->addWidget(lineEdit2, 2, 3);
//        layout->addWidget(lineEdit3, 2, 5);

//        layout->addWidget(list1, 3, 1);
//        layout->addWidget(list2, 3, 3);
//        layout->addWidget(list3, 3, 5);

//        layout->setColumnStretch(1, 1);
//        layout->setColumnStretch(3, 2);
//        layout->setColumnStretch(5, 3);
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
       QPushButton *btnShow = new QPushButton(QObject::tr("Show"), &w);
       btnLayout->addWidget(btnInsert);
       btnLayout->addWidget(btnDetele);
       btnLayout->addWidget(btnShow);

       QVBoxLayout *mianLayout = new QVBoxLayout(&w);
       mianLayout->addLayout(layou);
       mianLayout->addWidget(listView);
       mianLayout->addLayout(btnLayout);
      // setLayout(mianLayout);
    //layout->setVerticalSpacing(50);
    //layout->setHorizontalSpacing(80);
    w.centralWidget()->setLayout(mianLayout);
    w.show();

    return a.exec();
}
