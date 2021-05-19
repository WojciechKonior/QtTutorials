#include <QCoreApplication>
#include "mythread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 1st thread
    MyThread mThr1;
    mThr1.name = "Thread 1";
    mThr1.start(QThread::HighestPriority);

    // 2nd thread
    MyThread mThr2;
    mThr2.name = "Thread 2";
    mThr2.start(QThread::HighPriority);

    // 3rd thread
    MyThread mThr3;
    mThr3.name = "Thread 3";
    mThr3.start(QThread::NormalPriority);

    // 4th thread
    MyThread mThr4;
    mThr4.name = "Thread 4";
    mThr4.start(QThread::LowPriority);

    // 5th thread
    MyThread mThr5;
    mThr5.name = "Thread 5";
    mThr5.start(QThread::LowestPriority);

    return a.exec();
}
