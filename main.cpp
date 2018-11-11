#include "vendingmachine.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VendingMachine w;
    w.show();

    return a.exec();
}
