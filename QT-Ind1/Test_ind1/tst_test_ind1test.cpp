#include <QString>
#include <QtTest>

#include "t_set.h"

class Test_ind1Test : public QObject
{
    Q_OBJECT

public:
    Test_ind1Test();

private Q_SLOTS:
    void testempty();
    void testempty_data();
    void testinsert();
    void testinsert_data();
    void testerase();
    void testerase_data();
    void testfind();
    void testfind_data();
    void testcombine();
    void testcombine_data();
    void testintersection();
    void testintersection_data();
    void testadd();
    void testadd_data();
    void testeq();
    void testeq_data();
    void testneq();
    void testneq_data();
    void testassign();
    void testassign_data();
    void testexclude();
    void testexclude_data();


};

Test_ind1Test::Test_ind1Test(){}

void Test_ind1Test:: testempty_data()
{
    QTest::addColumn<bool>("first");
    QTest::addColumn<bool>("result");

    QTest::newRow("test_empty_1")  << true << false;
    QTest::newRow("test_empty_2")  << false << true;

}

void Test_ind1Test::testempty()
{
    t_set a;
    QFETCH(bool, first);
    QFETCH(bool, result);
    QCOMPARE(a.test_empty(first), result);
}

void Test_ind1Test:: testfind_data()
{
    QTest::addColumn<bool>("first");
    QTest::addColumn<bool>("result");

    QTest::newRow("test_find_1")  << true << true;
    QTest::newRow("test_find_2")  << false << false;

}

void Test_ind1Test::testfind()
{
    t_set a;
    QFETCH(bool, first);
    QFETCH(bool, result);
    QCOMPARE(a.test_find(first), result);
}

void Test_ind1Test:: testinsert_data()
{
    QTest::addColumn<bool>("first");
    QTest::addColumn<int>("second");
    QTest::addColumn<bool>("result");

    QTest::newRow("test_insert_1")  << true << 1 << true;
    QTest::newRow("test_insert_2")  << false << 1 << true;

}

void Test_ind1Test::testinsert()
{
    t_set a;
    QFETCH(bool, first);
    QFETCH(int, second);
    QFETCH(bool, result);
    QCOMPARE(a.test_insert(first,second), result);
}

void Test_ind1Test:: testerase_data()
{
    QTest::addColumn<bool>("first");
    QTest::addColumn<bool>("result");

    QTest::newRow("test_erase_1")  << true  << true;
    QTest::newRow("test_erase_2")  << false << false;

}

void Test_ind1Test::testerase()
{
    t_set a;
    QFETCH(bool, first);
    QFETCH(bool, result);
    QCOMPARE(a.test_erase(first), result);
}

void Test_ind1Test:: testcombine_data()
{
    QTest::addColumn<bool>("first");
    QTest::addColumn<bool>("result");

    QTest::newRow("test_combine_1")  << true << true;
    QTest::newRow("test_combine_2")  << false << true;

}

void Test_ind1Test::testcombine()
{
    t_set a;
    QFETCH(bool, first);
    QFETCH(bool, result);
    QCOMPARE(a.test_operator_combine(first), result);
}

void Test_ind1Test:: testintersection_data()
{
    QTest::addColumn<bool>("first");
    QTest::addColumn<bool>("result");

    QTest::newRow("test_intersection_1")  << true << true;
    QTest::newRow("test_intersection_2")  << false << false;

}

void Test_ind1Test::testintersection()
{
    t_set a;
    QFETCH(bool, first);
    QFETCH(bool, result);
    QCOMPARE(a.test_operator_intersection(first), result);
}

void Test_ind1Test:: testadd_data()
{
    QTest::addColumn<int>("first");
    QTest::addColumn<bool>("result");

    QTest::newRow("test_add_1")  << 10 << true;
    QTest::newRow("test_add_2")  << 20 << true;
    QTest::newRow("test_add_3")  << 30 << true;
    QTest::newRow("test_add_4")  << 25 << true;

}

void Test_ind1Test::testadd()
{
    t_set a;
    QFETCH(int, first);
    QFETCH(bool, result);
    QCOMPARE(a.test_operator_add(first), result);
}

void Test_ind1Test:: testeq_data()
{
    QTest::addColumn<bool>("first");
    QTest::addColumn<bool>("result");

    QTest::newRow("test_eq_1")  << true << false;
    QTest::newRow("test_eq_2")  << false << true;
}

void Test_ind1Test::testeq()
{
    t_set a;
    QFETCH(bool, first);
    QFETCH(bool, result);
    QCOMPARE(a.test_operator_eq(first), result);
}

void Test_ind1Test:: testassign_data()
{
    QTest::addColumn<bool>("first");
    QTest::addColumn<bool>("result");

    QTest::newRow("test_assign_1")  << true << true;
    QTest::newRow("test_assign_2")  << false << true;
}

void Test_ind1Test::testassign()
{
    t_set a;
    QFETCH(bool, first);
    QFETCH(bool, result);
    QCOMPARE(a.test_operator_assign(first), result);
}

void Test_ind1Test:: testneq_data()
{
    QTest::addColumn<bool>("first");
    QTest::addColumn<bool>("result");

    QTest::newRow("test_neq_1")  << true << true;
    QTest::newRow("test_neq_2")  << false << false;
}

void Test_ind1Test::testneq()
{
    t_set a;
    QFETCH(bool, first);
    QFETCH(bool, result);
    QCOMPARE(a.test_operator_neq(first), result);
}

void Test_ind1Test:: testexclude_data()
{
    QTest::addColumn<int>("first");
    QTest::addColumn<bool>("result");

    QTest::newRow("test_exclude_1") << 1 << true;
    QTest::newRow("test_exclude_2") << 4 << true;

}

void Test_ind1Test::testexclude()
{
    t_set a;
    QFETCH(int, first);
    QFETCH(bool, result);
    QCOMPARE(a.test_operator_exclude(first), result);
}



QTEST_APPLESS_MAIN(Test_ind1Test)

#include "tst_test_ind1test.moc"
