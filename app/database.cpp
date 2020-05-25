#include "database.h"

#include <QDebug>

Database::Database()
{
    dbConnection();
    dbTableCreate();

}


void Database::dbConnection(){

    const QString DRIVER("QSQLITE");

    if(QSqlDatabase::isDriverAvailable(DRIVER)){
          db = QSqlDatabase::addDatabase(DRIVER);

          db.setDatabaseName(":memory:"); //TODO not persistant change to file path later

          if(!db.open())
              qDebug() << "ERROR: " << db.lastError();
    }
}

void Database::dbTableCreate(){
    // database definition
    QSqlQuery query("CREATE TABLE notes (id INTEGER PRIMARY KEY, text TEXT, tags TEXT)");

    if(!query.isActive())
            qDebug() << "ERROR: " << query.lastError().text();
}

void Database::dbSQLinsert(const QString &newNoteText){
    QSqlQuery query;

    query.prepare("INSERT INTO notes(text) VALUES(?)");
    query.addBindValue(newNoteText);

    if(!query.exec())
        qDebug() << "ERROR db insert: " << query.lastError().text();
}

QSqlQuery Database::dbSQLselect(const QString &searchTerm){
    QSqlQuery query;

    query.prepare("SELECT text FROM notes WHERE text LIKE ? ");
    query.addBindValue("%"+searchTerm+"%");

    if(!query.exec())
        qDebug() << "ERROR db search: " << query.lastError().text();


    return query;
}