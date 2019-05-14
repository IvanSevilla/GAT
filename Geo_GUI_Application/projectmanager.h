#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H


#include <QString>
#include <iostream>
#include <QDir>
#include <unistd.h>
#include <string>
#include <fstream>
#include "nholmann/json.hpp"

using json = nlohmann::json;
class ProjectManager
{
public:
    ProjectManager();
    json loadProject(QString filename);

    void saveProject(QString filename,json project);
    void saveSubproject(QString filename, json subproject, int _count);
    ~ProjectManager();
};

#endif // PROJECTMANAGER_H
