#include "raymainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RayMainWindow w;
    w.show();

    return a.exec();
}
