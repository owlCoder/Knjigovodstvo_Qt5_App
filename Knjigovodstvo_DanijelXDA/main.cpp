#include "prijavanasistem.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PrijavaNaSistem w;
    w.show();
    return a.exec();
}
