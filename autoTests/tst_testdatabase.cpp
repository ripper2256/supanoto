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
    void test_case1();

};

testDatabase::testDatabase()
{

}

testDatabase::~testDatabase()
{

}

void testDatabase::test_case1()
{
    Database db;
    db.dbConnection();
}

QTEST_APPLESS_MAIN(testDatabase)

#include "tst_testdatabase.moc"
