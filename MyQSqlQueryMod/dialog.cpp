#include "dialog.h"
#include "ui_dialog.h"

#include <QSqlTableModel>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // add and set the database dirver
    db = QSqlDatabase::addDatabase("QODBC");

    // setup the database connections
    db.setHostName("LOCALHOST\\SQLEXPRESS");
    db.setDatabaseName("mydsn64");

    db.open();

    // define 3 kinds of database model
    this->model = new QSqlQueryModel();
    this->tmodel = new QSqlTableModel();
    this->rtmodel = new QSqlRelationalTableModel(this);

    // setup the table
    model->setQuery("SELECT [ID], [FirstName], [LastName] FROM [test].[dbo].[People]");

    tmodel->setTable("People");
    tmodel->select();

    rtmodel->setTable("People");
    rtmodel->setRelation(0, QSqlRelation("wages", "id", "salary"));
    rtmodel->select();

    qDebug() << model->lastError().text();

    ui->tableView->setModel(rtmodel);
}

Dialog::~Dialog()
{
    db.close();
    delete ui;
}

