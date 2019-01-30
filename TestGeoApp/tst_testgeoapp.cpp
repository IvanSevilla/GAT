#include <QtTest>

// add necessary includes here

class TestGeoApp : public QObject
{
    Q_OBJECT

public:
    TestGeoApp();
    ~TestGeoApp();

private slots:
    void test_case1();

};

TestGeoApp::TestGeoApp()
{

}

TestGeoApp::~TestGeoApp()
{

}

void TestGeoApp::test_case1()
{

}

QTEST_APPLESS_MAIN(TestGeoApp)

#include "tst_testgeoapp.moc"
