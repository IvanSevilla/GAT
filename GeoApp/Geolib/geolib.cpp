#include "geolib.h"


Geolib::Geolib()
{
}

void Geolib::ReadFile(string path){
    // Inicialitzem un string per a guardar les linies del fitxer
    char readLine[256];
    // Obrim el fitxer
    ifstream fil(path);
     // Llegim cada linea
    while(!fil.eof()) {
         fil.getline(readLine, 256);
         cout << readLine << endl;
      }
      fil.close();
}
