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
#include <QtMath>

class FittingPlane
{
public:
    FittingPlane();
    pcl::PointXYZI planeCoef;
    // Extret i modificat de http://pointclouds.org/documentation/tutorials/planar_segmentation.php
    std::pair<float,std::pair<float,float>> planeCalc(std::vector<pcl::PointXYZ> & _vec );
    // Funcio creada a partir de les formules que ens han ofert els investigadors de la facultat
    // de ciencies de la terra
    std::pair<qreal,qreal> computeDip(std::pair<float,std::pair<float,float>> _p);
    std::pair<qreal,qreal> computeStereoplotPosition(std::vector<pcl::PointXYZ> & _vec );

};

#endif // FITTINGPLANE_H
