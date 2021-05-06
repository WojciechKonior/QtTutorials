#include "mythread.h"
#include <QtCore>
#include <QDebug>

MyThread::MyThread()
{

}

void MyThread::run()
{
    for (int i = 0; i<1000; i++)
        qDebug() << this-> name << " is running, result = " << i;
}
