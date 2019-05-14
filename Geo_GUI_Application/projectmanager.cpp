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
ProjectManager::~ProjectManager(){}
