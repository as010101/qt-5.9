#include "widget.h"

#include <QApplication>
#include <sys/time.h>
#include <pthread.h>

int main(int argc, char *argv[])
{
    struct timeval time_t;
    gettimeofday(&time_t,NULL);
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
