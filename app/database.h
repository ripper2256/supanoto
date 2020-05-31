#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
// imports for QT Sql
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QList>
#include "note.h"

class Database
{
public:
    Database();

    void dbConnection();
    void dbTableCreate();
    void dbSQLinsert(const QString &newNoteText);
    QList<Note> dbSQLselect();
    QList<Note> dbSQLselect(const QString &searchTerm);
    void dbSQLdelete(const int &id);


    const int TABLE_TEXT_ID = 1;

private:
    QSqlDatabase db;
    QList<Note> queryToNoteList(QSqlQuery &sqlQuery);
};

#endif // DATABASE_H
