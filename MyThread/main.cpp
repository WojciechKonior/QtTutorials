#include <QCoreApplication>
#include "mythread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Thread definitions
    MyThread mThr1, mThr2, mThr3, mThr4, mThr5;

    // Setting thread names
    mThr1.name = "Thread 1";
    mThr2.name = "Thread 2";
    mThr3.name = "Thread 3";
    mThr4.name = "Thread 4";
    mThr5.name = "Thread 5";

    // Running threads with different priorities
    mThr1.start(QThread::HighestPriority);
    mThr2.start(QThread::NormalPriority);
    mThr3.start(QThread::LowestPriority);
    mThr4.start(QThread::HighPriority);
    mThr5.start(QThread::LowPriority);

    return a.exec();
}
