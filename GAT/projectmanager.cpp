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
           int _fr = 0;
           QString _frase;
           double phi,kappa,omega,Ycam,Zcam,Xcam,f,xpp,ypp,k1,k2,psx,psy,P1,P2,skew;
           while (! ficheroEntrada.eof() ) {
               getline (ficheroEntrada,frase);
               _frase = frase.c_str();
               switch(_fr){
               case 1:
                   phi=_frase.toDouble();
                   _fr++;
                   break;
               case 2:
                   kappa=_frase.toDouble();
                   _fr++;
                   break;
               case 3:
                   omega=_frase.toDouble();
                   _fr++;
                   break;
               case 4:
                   Ycam=_frase.toDouble();
                   _fr++;
                   break;
               case 5:
                   Zcam=_frase.toDouble();
                   _fr++;
                   break;
               case 6:
                   Xcam=_frase.toDouble();
                   _fr++;
                   break;
               case 7:
                   f=_frase.toDouble();
                   _fr++;
                   break;
               case 8:
                   xpp=_frase.toDouble();
                   _fr++;
                   break;
               case 9:
                   ypp=_frase.toDouble();
                   _fr++;
                   break;
               case 10:
                   k1=_frase.toDouble();
                   _fr++;
                   break;
               case 11:
                   k2=_frase.toDouble();
                   _fr++;
                   break;
               case 12:
                   psx=_frase.toDouble();
                   _fr++;
                   break;
               case 13:
                   psy=_frase.toDouble();
                   _fr++;
                   break;
               case 15:
                   P1=_frase.toDouble();
                   _fr++;
                   break;
               case 16:
                   P2=_frase.toDouble();
                   _fr++;
                   break;
               case 17:
                   skew=_frase.toDouble();
                   _fr++;
                   break;
               default:
                   _fr++;
                   break;
               }



           }

           ficheroEntrada.close();
           f = f / 1000; //distancia focal en metros
           xpp = (xpp - (_imWidth/ 2.0)); // Punt Principal x (xpp-(nºpixels/2))en pixels*micras
           ypp = (ypp - (_imHeight / 2.0)); // Punt Principal y (ypp-(nºpixels/2))en pixels*micras
           psx = psx / 1000000;//15 mida de pixel x (micras/1000000)en metres
           psy = psy / 1000000; //16 mida de pixel y (micras/1000000)en metres
           // Calculs angle camera
           omega = omega * ((2 * M_PI) / 360);
           phi = phi * ((2 * M_PI) / 360);
           kappa = kappa * ((2 * M_PI) / 360);
           // Calculs angle camera
           _matrix[0][0] = qCos(phi) * qCos(kappa);
           _matrix[0][1] = -qCos(phi) * qSin(kappa);
           _matrix[0][2] = qSin(phi);
           _matrix[1][0] = qCos(omega) * qSin(kappa) + (qSin(omega) * qSin(phi) * qCos(kappa));
           _matrix[1][1] = (qCos(omega) * qCos(kappa)) - (qSin(omega) * qSin(phi) * qSin(kappa));
           _matrix[1][2] = -qSin(omega) * qCos(phi);
           _matrix[2][0] = (qSin(omega) * qSin(kappa)) - (qCos(omega) * qSin(phi) * qCos(kappa));
           _matrix[2][1] = (qSin(omega) * qCos(kappa)) + (qCos(omega) * qSin(phi) * qSin(kappa));
           _matrix[2][2] = qCos(omega) * qCos(phi);
       }
    return _matrix;
}
void ProjectManager::readPointCloud(pcl::PointCloud<pcl::PointXYZ>* data,QString filename){
    std::fstream ficheroEntrada;
    std::string frase;
    QString _f;
    float x,y,z;
    ficheroEntrada.open ( filename.toStdString().c_str() , std::ios::in);
       if (ficheroEntrada.is_open()) {

           while (! ficheroEntrada.eof() ) {
               getline (ficheroEntrada,frase);
               _f = frase.c_str();
               if(_f != ""){
               QStringList _l=_f.split(" ");
               x=_l[0].toFloat();
               y=_l[1].toFloat();
               z=_l[2].split("/r")[0].toFloat();
               pcl::PointXYZ _pt(x,y,z);
               if(!isContained(_pt,data)){
                  data->push_back(_pt);
               }
            }
       }
    }
    ficheroEntrada.close();
}
std::pair<float,std::pair<float,float>> ProjectManager::readGeoData(QString filename){
    std::fstream ficheroEntrada;
    std::string frase;
    QString _f;
    int i = 0;
    float pixelsize = 0;
    float xcoord,ycoord;
    ficheroEntrada.open ( filename.toStdString().c_str() , std::ios::in);
       if (ficheroEntrada.is_open()) {

           while (! ficheroEntrada.eof() ) {
               getline (ficheroEntrada,frase);
               _f = frase.c_str();
               if(_f != ""){
                   if(i == 0){
                       pixelsize = _f.toFloat();
                   }if(i == 4){
                       xcoord = _f.toFloat();
                   }if(i == 5){
                       ycoord = _f.toFloat();
                   }
                   i++;


               }

           }
       }
    ficheroEntrada.close();
    std::pair<float,float> _pt(xcoord,ycoord);

    std::pair<float,std::pair<float,float>> _coord (pixelsize,_pt);
    return _coord;

}
bool ProjectManager::isContained(pcl::PointXYZ pt, pcl::PointCloud<pcl::PointXYZ> *data){
    if(!data->empty()){
        return false;
    }
    for(size_t i = 0; i<data->size();i++){
        if(qFabs(data->at(i).x -pt.x) <= std::numeric_limits<qreal>::epsilon()&& qFabs(data->at(i).y-pt.y)<= std::numeric_limits<qreal>::epsilon() && qFabs(data->at(i).z- pt.z)<= std::numeric_limits<qreal>::epsilon()){
            return true;
        }
    }
    return false;
}
ProjectManager::~ProjectManager(){}
