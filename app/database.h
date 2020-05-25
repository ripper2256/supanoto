#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
// imports for QT Sql
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

class Database
{
public:
    Database();

    void dbConnection();
    void dbTableCreate();
    void dbSQLinsert(const QString &newNoteText);
    QSqlQuery dbSQLselect(const QString &searchTerm);

private:
    QSqlDatabase db;
};

#endif // DATABASE_H
