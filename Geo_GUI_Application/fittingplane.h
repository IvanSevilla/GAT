#ifndef FITTINGPLANE_H
#define FITTINGPLANE_H
#include <iostream>
#include <pcl/ModelCoefficients.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <QDebug>
class FittingPlane
{
public:
    FittingPlane();
    pcl::PointXYZI planeCoef;
    // Extret i modificat de http://pointclouds.org/documentation/tutorials/planar_segmentation.php
    void planeCalc(std::vector<pcl::PointXYZ> & _vec );

};

#endif // FITTINGPLANE_H
