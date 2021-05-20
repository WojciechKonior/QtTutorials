#ifndef DIALOG_H
#define DIALOG_H

#include "mythread.h"
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    MyThread *mThread;

private:
    Ui::Dialog *ui;

public slots:
    void onNumberChanged(int);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};
#endif // DIALOG_H
