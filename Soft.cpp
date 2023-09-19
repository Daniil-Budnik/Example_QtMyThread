
#include "Soft.h"

Soft::Soft(QObject *parent) : QObject(parent) {

    myObject = new MyObject();

    connect(myObject, &MyObject::mySignal, this, &Soft::mySlot);
    connect(this, &Soft::startTimer, myObject, &MyObject::startTick);
    connect(this, &Soft::stopTimer, myObject, &MyObject::stopTick);

    myThread = new QThread(this);
    connect(this, &Soft::destroyed, myThread, &QThread::quit);

    myObject->moveToThread(myThread);
    myThread->start();
}

Soft::~Soft() {
    delete myThread;
    delete myObject;
}

void Soft::mySlot() {
    qDebug() << &myObject->count;
    qDebug() << "Check!";
}

void Soft::timerStart() {
    emit startTimer();
}

void Soft::timerStop() {
    emit stopTimer();
}
