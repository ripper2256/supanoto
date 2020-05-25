#include <QtTest>
#include "database.h"
// add necessary includes here

class testDatabase : public QObject
{
    Q_OBJECT

public:
    testDatabase();
    ~testDatabase();

private slots:
    void test_case_add();
    void test_case_del();
    void test_case_SQLinjection();

};

testDatabase::testDatabase()
{

}

testDatabase::~testDatabase()
{

}

void testDatabase::test_case_add()
{
    Database db;

    QString input = "first test note";
    db.dbSQLinsert(input);
    QSqlQuery query = db.dbSQLselect("firs");
    query.first();
    QString result = query.value(db.TABLE_TEXT_ID).toString();

    QCOMPARE(input, result);
}

void testDatabase::test_case_del()
{
    Database db;

    QString input = "first test note";
    db.dbSQLinsert(input);
    input = "second test note";
    db.dbSQLinsert(input);
    QSqlQuery query = db.dbSQLselect("firs");
    query.first();
    int id = query.value(0).toInt();
    db.dbSQLdelete(id);
    QSqlQuery query2 = db.dbSQLselect("firs");

    QCOMPARE(-1, query2.size());
}

void testDatabase::test_case_SQLinjection()
{
    Database db;

    QString input = "first test note";
    db.dbSQLinsert(input);
    QSqlQuery query = db.dbSQLselect("name’); DELETE FROM notes; –");
    query.first();
    query = db.dbSQLselect("firs");
    query.first();
    QString result = query.value(db.TABLE_TEXT_ID).toString();

    QCOMPARE(input, result);
}

QTEST_APPLESS_MAIN(testDatabase)

#include "tst_testdatabase.moc"
