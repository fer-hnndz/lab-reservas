#include "cframe.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Cframe w;
    w.show();
    return a.exec();
}
