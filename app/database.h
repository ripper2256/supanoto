#ifndef DATABASE_H
#define DATABASE_H

#include <QStringListModel>
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
    Q_PROPERTY(QStringListModel* model READ model NOTIFY modelChanged)
public:
    explicit Database(QObject *parent = nullptr);

    void dbConnection();
    void dbTableCreate();

    Q_INVOKABLE void dbSQLinsert(const QString &newNoteText);
    QList<Note> dbSQLselect();
    QList<Note> dbSQLselect(const QString &searchTerm);

    Q_INVOKABLE void dbSQLdelete(const int &id);
    QStringListModel* model() const {return m_model;}

    const int TABLE_TEXT_ID = 1;
signals:
    void modelChanged();
private:
    QSqlDatabase db;
    QList<Note> queryToNoteList(QSqlQuery &sqlQuery);
    QStringListModel* m_model;
};

#endif // DATABASE_H
