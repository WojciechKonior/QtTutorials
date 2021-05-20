#include <QCoreApplication>
#include "mythread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 1st thread
    MyThread mThr1;
    mThr1.name = "Thread 1";
    mThr1.start(QThread::HighestPriority);
    mThr1.wait(); // waiting until thr1 finish

    // 2nd thread
    MyThread mThr2;
    mThr2.name = "Thread 2";
    mThr2.start(QThread::HighPriority);
    mThr2.wait();

    // 3rd thread
    MyThread mThr3;
    mThr3.name = "Thread 3";
    mThr3.start(QThread::NormalPriority);
    mThr3.wait();

    // 4th thread
    MyThread mThr4;
    mThr4.name = "Thread 4";
    mThr4.start(QThread::LowPriority);
    mThr4.wait();

    // 5th thread
    MyThread mThr5;
    mThr5.name = "Thread 5";
    mThr5.start(QThread::LowestPriority);
    mThr5.wait();

    return a.exec();
}
