
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
#include "pcl/point_types.h"
#include "pcl/point_cloud.h"



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

    void readPointCloud(pcl::PointCloud<pcl::PointXYZ>* data,QString filename);
    std::pair<float,std::pair<float,float>> readGeoData(QString filename);
    bool isContained(pcl::PointXYZ pt,pcl::PointCloud<pcl::PointXYZ>* data);
    ~ProjectManager();
};

#endif // PROJECTMANAGER_H
