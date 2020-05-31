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
    // Database tests
    void test_case_add();
    void test_case_del();
    void test_case_SQLinjection();
    void test_case_db_getAll();

    // Note tests
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

void tst_unitTestClass::test_case_db_getAll(){
    Database db;

    QString input1 = "Note1: Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.";
    QString input2 = "Note2: Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam";
    QString input3 = "Note3: Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam";

    db.dbSQLinsert(input1);
    db.dbSQLinsert(input2);
    db.dbSQLinsert(input3);

    QList<Note> resultList = db.dbSQLselect();

    QCOMPARE(input1, resultList.value(0).getNote());
    QCOMPARE(input2, resultList.value(1).getNote());
    QCOMPARE(input3, resultList.value(2).getNote());
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
