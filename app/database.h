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

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);

    void dbConnection();
    void dbTableCreate();

    Q_INVOKABLE void dbSQLinsert(const QString &newNoteText);
    Q_INVOKABLE QList<Note> dbSQLselect();
    Q_INVOKABLE QList<Note> dbSQLselect(const QString &searchTerm);

    Q_INVOKABLE void dbSQLdelete(const int &id);


    const int TABLE_TEXT_ID = 1;

private:
    QSqlDatabase db;
    QList<Note> queryToNoteList(QSqlQuery &sqlQuery);
};

#endif // DATABASE_H
