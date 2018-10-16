#include <QtTest>

// add necessary includes here

class GeolibTest : public QObject
{
    Q_OBJECT

public:
    GeolibTest();
    ~GeolibTest();

private slots:
    void test_case1();

};

GeolibTest::GeolibTest()
{

}

GeolibTest::~GeolibTest()
{

}

void GeolibTest::test_case1()
{

}

QTEST_APPLESS_MAIN(GeolibTest)

#include "tst_geolibtest.moc"
