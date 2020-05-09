#ifndef DIALOG_H
#define DIALOG_H


#include <QDialog>  //新增ui此处要加头文件



QT_BEGIN_NAMESPACE

namespace Ui { class Dialog;}

QT_END_NAMESPACE



class Dialog:public  QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;


};
































#endif // DIALOG_H
