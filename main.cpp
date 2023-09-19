#include <QCoreApplication>
#include <QDebug>

#include "Soft.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    Soft soft;
    soft.timerStart();
    return QCoreApplication::exec();
}
