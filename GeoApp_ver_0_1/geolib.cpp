#include "geolib.h"


Geolib::Geolib()
{
}

void Geolib::ReadFile(QString path){
    // Inicialitzem un string per a guardar les linies del fitxer
    char readLine[256];
    cout<< "reading File"<<endl;
    // Obrim el fitxer
    Q_INIT_RESOURCE(resources);
    QFile file;
    //QDir("");
    file.setFileName(path);
    //QDir::setCurrent("/home");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    //ifstream fil;
    QString line;
    QTextStream stream(&file);
     while (!stream.atEnd()){
         line = stream.readLine();
         qDebug() << "line: "<<line;
     }
     file.close();
    //fil.open(path);
     // Llegim cada linea
    //fil.getline(readLine,256);
    //cout << readLine << endl;
    //while(!fil.eof()) {
      //   fil>>readLine;
       //  cout << readLine << endl;
      //}
      //fil.close();
}
