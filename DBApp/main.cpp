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

    // Setup connections
    db.setConnectOptions();

    // Connection string
//    QString dsn = QString("DRIVER={SQL Native Client);SERVER=%1;DATABASE=%2;UID=sa;PWD=;").arg(serverName).arg(dbName);
    QString dsn = QString("DRIVER={SQL Native Client);SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(servername).arg(dbname);

    db.setDatabaseName(dsn);

    if(db.open()){
        qDebug() << "Opened!";

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
