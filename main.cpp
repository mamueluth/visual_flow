#include "app/include/window/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VisualFlow w;
    w.show();
    return a.exec();
}
