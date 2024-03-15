#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[]) // entry point
{
    QApplication a(argc, argv);
    Widget w;
    w.show(); // show : display in screen
    return a.exec();
}
