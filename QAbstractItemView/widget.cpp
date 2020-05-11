#include "widget.h"
#include "ui_widget.h"
#include <QColumnView>
#include <QVBoxLayout>
#include <iostream>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent),ui(new Ui::Widget),model (new QStandardItemModel)
{

    ui->setupUi(this);
        QStandardItem *name = new QStandardItem("Name");
        QStandardItem *firstName = new QStandardItem("First Name");
        QStandardItem *lastName = new QStandardItem("Last Name");
        name->setBackground(QBrush(QColor(255,255,0)));
        name->appendRow(firstName);
        name->appendRow(lastName);
        name->setEditable(false);
        model->appendRow(name);

        QStandardItem *john = new QStandardItem("John");
        QStandardItem *smith = new QStandardItem("Smith");

        firstName->appendRow(john);
        lastName->appendRow(smith);

        QStandardItem *address = new QStandardItem("Address");
        QStandardItem *street = new QStandardItem("Street");
        QStandardItem *city = new QStandardItem("City");
        QStandardItem *state = new QStandardItem("State");
        QStandardItem *country = new QStandardItem("Country");
        for (int i=0;i<1000;i++)
        {
        QStandardItem *country = new QStandardItem("Country");
        address->appendRow(country);
        }
        model->appendRow(address);

        QColumnView *columnView = new QColumnView;
        columnView->setModel(model);

        QVBoxLayout *vLayout = new QVBoxLayout(this);
        vLayout->addWidget(columnView);
       // QMessageBox::information(NULL, "Title", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);



}

void Widget::mouseclicked(const QModelIndex &index)
{
    QStandardItem *item = model->itemFromIndex(index);
    item->setData(QString("xxxxxx"));

    QMessageBox::information(NULL, "Title", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    // Do stuff with the item ...
}

Widget::~Widget()
{
    delete ui;
}

