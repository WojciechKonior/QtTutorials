#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSql>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Make a connection to the database
    QString servername = "LOCALHOST\\SQLEXPRESS";
    QString dbname = "test";

    // Add database driver setup
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    QSqlDatabase db2 = QSqlDatabase::addDatabase("QODBC");

    db2.setHostName(servername);
    db2.setDatabaseName("mydsn64");

    if(db2.open()){
        qDebug() << "Opened";
        db2.close();
    } else {
        qDebug() << db2.lastError().text();
    }

    // Setup connections
    db.setConnectOptions();

    // Connection string
//    QString dsn = QString("DRIVER={SQL Native Client);SERVER=%1;DATABASE=%2;UID=sa;PWD=;").arg(serverName).arg(dbName);
    QString dsn = QString("DRIVER={SQL Native Client);SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(servername).arg(dbname);

    db.setDatabaseName(dsn);

    if(db.open()){
        qDebug() << "Opened!";

        QString sQuery = "INSERT INTO [test].[dbo].[People] ([FirstName],[LastName]) VALUES(:first,:last)";
        QSqlQuery qry_;
        qry_.prepare(sQuery);
        qry_.bindValue(":first", "Wojciech");
        qry_.bindValue(":last", "Konior");

        if(qry_.exec()){
            qDebug() << "Record Inserted";
        }

        QSqlQuery qry;

        if(qry.exec("SELECT * FROM [test].[dbo].[People]")){
            while(qry.next()){
                qDebug() << qry.value(1).toString();
            }
        } else {
            qDebug() << "Error = " << db.lastError().text();
        }

        qDebug() << "Closing ... ";
        db.close();
    } else {
        qDebug() << "Error = " << db.lastError().text();
    }
    return a.exec();
}
