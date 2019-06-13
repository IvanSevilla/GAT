#include "fittingplane.h"

FittingPlane::FittingPlane()
{

}

std::pair<float,float> FittingPlane::planeCalc(std::vector<pcl::PointXYZ> &_vec){
    std::pair<float,float> _n= {-1,-1};
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

    for(u_long i = 0; i<_vec.size();i++){
        cloud->push_back(_vec.at(i));
    }

    qDebug()<< "Point cloud data: " << cloud->points.size () << " points" ;
      for (size_t i = 0; i < cloud->points.size (); ++i)
        qDebug() << "    " << cloud->points[i].x << " "
                            << cloud->points[i].y << " "
                            << cloud->points[i].z ;

      pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);
        pcl::PointIndices::Ptr inliers (new pcl::PointIndices);
        // Create the segmentation object
        pcl::SACSegmentation<pcl::PointXYZ> seg;
        // Optional
        seg.setOptimizeCoefficients (true);
        // Mandatory
        seg.setModelType (pcl::SACMODEL_PLANE);
        seg.setMethodType (pcl::SAC_RANSAC);
        seg.setDistanceThreshold (0.01);

        seg.setInputCloud (cloud);
        seg.segment (*inliers, *coefficients);

        if (inliers->indices.size () == 0)
        {
          PCL_ERROR ("Could not estimate a planar model for the given dataset.");
          return _n;
        }else{

        qDebug() << "Model coefficients: " << coefficients->values[0] << " "
                                            << coefficients->values[1] << " "
                                            << coefficients->values[2] << " "
                                            << coefficients->values[3] ;

        qDebug() << "Model inliers: " << inliers->indices.size () ;
        for (size_t i = 0; i < inliers->indices.size (); ++i)
          qDebug() << inliers->indices[i] << "    " << cloud->points[inliers->indices[i]].x << " "
                                                     << cloud->points[inliers->indices[i]].y << " "
                                                     << cloud->points[inliers->indices[i]].z ;
        _n.first=coefficients->values[0];
        _n.second=coefficients->values[1];
        return _n;
       }

}
