#include "geolib_global.h"
#include "geolib.h"
using namespace std;

int main() {
    Geolib g = Geolib();
    QString path = ":/test/Montserrat_Ortho/projecteMontserrat_1.txt";
    qDebug() << "file: "<<path;
    g.ReadFile(path);
    return 0;
}
