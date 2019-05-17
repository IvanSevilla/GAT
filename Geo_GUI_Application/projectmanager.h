#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H


#include <QString>
#include <iostream>
#include <fstream>
#include <QDir>
#include <QDebug>
#include <unistd.h>
#include <string>
#include <QtMath>

#include "glm/glm.hpp"
#include "nholmann/json.hpp"

using json = nlohmann::json;
class ProjectManager
{
public:
    ProjectManager();
    json loadProject(QString filename);

    void saveProject(QString filename,json project);
    void saveSubproject(QString filename, json subproject, int _count);
    glm::mat4 readMatrix(QString matrixFile);
    glm::mat4 readCalibrationMatrix(QString calibFile,int _imWidth,int _imHeight);
    ~ProjectManager();
};

#endif // PROJECTMANAGER_H
