#include "MyObject.h"

MyObject::MyObject(QObject *parent) : QObject(parent) {
    timer = new QTimer(this); count = 0;
    connect(timer, &QTimer::timeout, this, &MyObject::tick);
}

MyObject::~MyObject() {
    delete timer;
}

void MyObject::tick() {
    qDebug() << QDateTime::currentDateTime().toString("Tick: hh:mm:ss:zzz");
    count += 1;
    if(count > countBorder){
        emit mySignal();
        count = 0;
        qDebug() << &count;
    }
}

void MyObject::startTick() {
    if(!timer->isActive()) timer->start(1000);
    name = "Иван";
}

void MyObject::stopTick() {
    if(timer->isActive()) timer->stop();
}
