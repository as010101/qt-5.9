#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   //void Message();
    MainWindow(QWidget *parent = nullptr);
    void contextMenuEvent(QContextMenuEvent *event);
    ~MainWindow();
    QPushButton *button;
public slots:
    void Message();
signals:
    void sig111x();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
