#include "geolib_global.h"
#include "geolib.h"
using namespace std;

int main() {
    Geolib g = Geolib();
    string path = "./testfiles/Montserrat_Ortho/projecteMontserrat.txt";

    g.ReadFile(path);
    return 0;
}
