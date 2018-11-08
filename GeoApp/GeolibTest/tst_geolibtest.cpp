#include <QtTest>
#include "../Geolib/geolib.h"
#include "../Geolib/geolib_global.h"
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
    string path = "../Geolib/Monstserrat_Ortho/projecteMontserrat.txt";
    Geolib g = Geolib();
    g.ReadFile(path);
}

GeolibTest::~GeolibTest()
{

}

void GeolibTest::test_case1()
{

}

QTEST_APPLESS_MAIN(GeolibTest)

#include "tst_geolibtest.moc"
