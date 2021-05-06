#include "mythread.h"
#include <QtCore>
#include <QDebug>

MyThread::MyThread()
{

}

void MyThread::run()
{
    for (int i = 0; i<1000; i++){

        // Declaration of mutex
        QMutex mutex;

        // Locking the thread to prevent data race
        mutex.lock();

        // Checking if the stop is true
        if(this->Stop)
            break;

        // Unlocking the mutex
        mutex.unlock();

        // Slowing the thread down
        this->sleep(5);

        // Printing some stats
        qDebug() << this-> name << " is running, result = " << i;
    }
}
