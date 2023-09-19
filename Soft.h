#ifndef MYTHREAD_SOFT_H
#define MYTHREAD_SOFT_H

#include <QObject>
#include <QThread>
#include <QDebug>

#include "MyObject.h"

class Soft : public QObject{

    Q_OBJECT

public:
    explicit Soft(QObject *parent = nullptr);
    ~Soft() override;

    void timerStart();
    void timerStop();

public slots:
    void mySlot();

signals:
    void startTimer();
    void stopTimer();

private:
    QThread *myThread;
    MyObject *myObject;
};


#endif
