#ifndef MYTHREAD_MYOBJECT_H
#define MYTHREAD_MYOBJECT_H

#include <QDateTime>
#include <QObject>
#include <QTimer>
#include <QDebug>

class MyObject : public QObject{

    Q_OBJECT

public:
    explicit MyObject(QObject *parent = nullptr);
    ~MyObject() override;
    int count;

    QString name;

public slots:
    void startTick();
    void stopTick();

signals:
    void mySignal();

private slots:
    void tick();

private:
    QTimer *timer;

    const int countBorder = 5;

};


#endif
