#include <QtTest>
#include "database.h"
#include "note.h"
// add necessary includes here

class tst_unitTestClass : public QObject
{
    Q_OBJECT

public:
    tst_unitTestClass();
    ~tst_unitTestClass();

private slots:
    void test_case_add();
    void test_case_del();
    void test_case_SQLinjection();

    void test_case_setAndGet();

};

tst_unitTestClass::tst_unitTestClass()
{

}

tst_unitTestClass::~tst_unitTestClass()
{

}

void tst_unitTestClass::test_case_add()
{
    Database db;

    QString input = "first test note";
    db.dbSQLinsert(input);
    QList<Note> resultList = db.dbSQLselect("firs");
    QString result = resultList.first().getNote();

    QCOMPARE(input, result);
}

void tst_unitTestClass::test_case_del()
{
    Database db;

    QString input = "first test note";
    db.dbSQLinsert(input);
    input = "second test note";
    db.dbSQLinsert(input);
    QList<Note> resultList = db.dbSQLselect("firs");
    int id = resultList.first().getID();
    db.dbSQLdelete(id);
    QList<Note> resultList2 = db.dbSQLselect("firs");

    QCOMPARE(true, resultList2.empty());
}

void tst_unitTestClass::test_case_SQLinjection()
{
    Database db;

    QString input = "first test note";
    db.dbSQLinsert(input);
    QList<Note> resultList = db.dbSQLselect("name’); DELETE FROM notes; –");
    resultList = db.dbSQLselect("firs");
    QString result = resultList.first().getNote();

    QCOMPARE(input, result);
}


void tst_unitTestClass::test_case_setAndGet()
{
    Note myNote;

    QString input = "first test note";
    myNote.setNote(input);
    QString result = myNote.getNote();

    QCOMPARE(input, result);
}

QTEST_APPLESS_MAIN(tst_unitTestClass)

#include "tst_unitTestClass.moc"
