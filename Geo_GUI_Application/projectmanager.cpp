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
               //qDebug()<< frase.c_str();
               _f = frase.c_str();
               if(!_f.contains("MATRIX")&&!_f.contains("VERSION")&&_f != ""){
                   QStringList _sl = _f.split("   ");
                   for (int i = 0; i<_sl.length();i++){
                       if(_sl.at(i).contains(" ")){
                            qDebug()<<_sl.at(i).split(" ");
                           _sl.replace(i,_sl.at(i).split(" ").at(1));
                       }
                       //if(_sl.at(i).contains("e+")){
                         //  _sl.replace(i,_sl.at(i).split("e+").at(0));
                       //}
                       _matrix[count][static_cast<ulong>(i)]=_sl.at(i).toFloat();
                       qDebug()<< _sl.at(i).toFloat();
               }
                   count++;
               }
           }


           ficheroEntrada.close();
       }
    return _matrix;
}
glm::mat4 ProjectManager::readCalibrationMatrix(QString calibFile){
    glm::mat4 _matrix;
    std::fstream ficheroEntrada;
    std::string frase;
    ficheroEntrada.open ( calibFile.toStdString().c_str() , std::ios::in);
       if (ficheroEntrada.is_open()) {

           while (! ficheroEntrada.eof() ) {
               getline (ficheroEntrada,frase);
               qDebug()<< frase.c_str();
           }

           ficheroEntrada.close();
       }
    return _matrix;
}

ProjectManager::~ProjectManager(){}
