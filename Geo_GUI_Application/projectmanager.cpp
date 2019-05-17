#include "projectmanager.h"

ProjectManager::ProjectManager()
{

}

json ProjectManager::loadProject( QString filename){
    json project;
    std::ifstream i(filename.toStdString());
    i >>project;
    i.close();
    return project;

}
void ProjectManager::saveProject(QString filename, json project){
    std::ofstream file(filename.toStdString());
    file<<project<< std::endl;
    file.close();
}
void ProjectManager::saveSubproject(QString filename, json subproject, int _count){

    QFileInfo _f(filename);
    std::ofstream file(_f.dir().path().toStdString()+"/subproject"+std::to_string(_count)+".json");
    file<<subproject<< std::endl;
    file.close();

}
glm::mat4 ProjectManager::readMatrix(QString matrixFile){
    glm::mat4 _matrix;
    std::fstream ficheroEntrada;
    std::string frase;
    QString _f;
    ulong count=0;
    ficheroEntrada.open ( matrixFile.toStdString().c_str() , std::ios::in);
       if (ficheroEntrada.is_open()) {

           while (! ficheroEntrada.eof() ) {
               getline (ficheroEntrada,frase);
               _f = frase.c_str();
               if(!_f.contains("MATRIX")&&!_f.contains("VERSION")&&_f != ""){
                   QStringList _sl = _f.split("   ");
                   for (int i = 0; i<_sl.length();i++){
                       if(_sl.at(i).contains(" ")){
                           _sl.replace(i,_sl.at(i).split(" ").at(1));
                       }
                       _matrix[count][static_cast<ulong>(i)]=_sl.at(i).toFloat();
               }
                   count++;
               }
           }


           ficheroEntrada.close();
       }
    return _matrix;
}
glm::mat4 ProjectManager::readCalibrationMatrix(QString calibFile,int _imWidth,int _imHeight){
    glm::mat4 _matrix;
    std::fstream ficheroEntrada;
    std::string frase;
    ficheroEntrada.open ( calibFile.toStdString().c_str() , std::ios::in);
       if (ficheroEntrada.is_open()) {
           ulong _col = 0,_row = 0;
           int _fr = 0;
           QString _frase;
           float phi,kappa,omega,Ycam,Zcam,Xcam,f,xpp,ypp,k1,k2,psx,psy,P1,P2,skew;
           while (! ficheroEntrada.eof() ) {
               getline (ficheroEntrada,frase);
               _frase = frase.c_str();
               switch(_fr){
               case 1:
                   phi=_frase.toFloat();
                   _fr++;
                   break;
               case 2:
                   kappa=_frase.toFloat();
                   _fr++;
                   break;
               case 3:
                   omega=_frase.toFloat();
                   _fr++;
                   break;
               case 4:
                   Ycam=_frase.toFloat();
                   _fr++;
                   break;
               case 5:
                   Zcam=_frase.toFloat();
                   _fr++;
                   break;
               case 6:
                   Xcam=_frase.toFloat();
                   _fr++;
                   break;
               case 7:
                   f=_frase.toFloat();
                   _fr++;
                   break;
               case 8:
                   xpp=_frase.toFloat();
                   _fr++;
                   break;
               case 9:
                   ypp=_frase.toFloat();
                   _fr++;
                   break;
               case 10:
                   k1=_frase.toFloat();
                   _fr++;
                   break;
               case 11:
                   k2=_frase.toFloat();
                   _fr++;
                   break;
               case 12:
                   psx=_frase.toFloat();
                   _fr++;
                   break;
               case 13:
                   psy=_frase.toFloat();
                   _fr++;
                   break;
               case 15:
                   P1=_frase.toFloat();
                   _fr++;
                   break;
               case 16:
                   P2=_frase.toFloat();
                   _fr++;
                   break;
               case 17:
                   skew=_frase.toFloat();
                   _fr++;
                   break;
               default:
                   _fr++;
                   break;
               }



           }

           ficheroEntrada.close();
           f = f / 1000; //distancia focal en metros
           xpp = (xpp - (_imWidth/ 2)); // Punt Principal x (xpp-(nºpixels/2))en pixels*micras
           ypp = (ypp - (_imHeight / 2)); // Punt Principal y (ypp-(nºpixels/2))en pixels*micras
           psx = psx / 1000000;//15 mida de pixel x (micras/1000000)en metres
           psy = psy / 1000000; //16 mida de pixel y (micras/1000000)en metres
           // Calculs angle camera
           omega = omega * ((2 * PI) / 360);
           phi = phi * ((2 * Math.PI) / 360);
           kappa = kappa * ((2 * Math.PI) / 360);
           // Calculs angle camera
           _matrix[0][0] = Math.Cos(phi) * Math.Cos(kappa);
           _matrix[0][1] = -Math.Cos(phi) * Math.Sin(kappa);
           _matrix[0][2] = Math.Sin(phi);
           _matrix[1][0] = (Math.Cos(omega) * Math.Sin(kappa)) + (Math.Sin(omega) * Math.Sin(phi) * Math.Cos(kappa));
           _matrix[1][1] = (Math.Cos(omega) * Math.Cos(kappa)) - (Math.Sin(omega) * Math.Sin(phi) * Math.Sin(kappa));
           _matrix[1][2] = -Math.Sin(omega) * Math.Cos(phi);
           _matrix[2][0] = (Math.Sin(omega) * Math.Sin(kappa)) - (Math.Cos(omega) * Math.Sin(phi) * Math.Cos(kappa));
           _matrix[2][1] = (Math.Sin(omega) * Math.Cos(kappa)) + (Math.Cos(omega) * Math.Sin(phi) * Math.Sin(kappa));
           _matrix[2][2] = Math.Cos(omega) * Math.Cos(phi);
       }
    return _matrix;
}

ProjectManager::~ProjectManager(){}
