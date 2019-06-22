#include "fittingplane.h"

FittingPlane::FittingPlane()
{

}

std::pair<float,std::pair<float,float>> FittingPlane::planeCalc(std::vector<pcl::PointXYZ> &_vec){
    std::pair<float,std::pair<float,float>> _n= {-3,{-1,-1}};
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

    for(u_long i = 0; i<_vec.size();i++){
        cloud->push_back(_vec.at(i));
    }

    //qDebug()<< "Point cloud data: " << cloud->points.size () << " points" ;
      //for (size_t i = 0; i < cloud->points.size (); ++i)
        //qDebug() << "    " << cloud->points[i].x << " "
                           // << cloud->points[i].y << " "
                            //<< cloud->points[i].z ;

      pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);
        pcl::PointIndices::Ptr inliers (new pcl::PointIndices);
        // Create the segmentation object
        pcl::SACSegmentation<pcl::PointXYZ> seg;
        // Optional
        seg.setOptimizeCoefficients (true);
        // Mandatory
        seg.setModelType (pcl::SACMODEL_PLANE);
        seg.setMethodType (pcl::SAC_RANSAC);
        seg.setDistanceThreshold (0.1);

        seg.setInputCloud (cloud);
        seg.segment (*inliers, *coefficients);

        if (inliers->indices.size () == 0)
        {
          //PCL_ERROR ("Could not estimate a planar model for the given dataset.");
          return _n;
        }else{

        //qDebug() << "Model coefficients: " << coefficients->values[0] << " "
                                           // << coefficients->values[1] << " "
                                            //<< coefficients->values[2] << " "
                                            //<< coefficients->values[3] ;

        //qDebug() << "Model inliers: " << inliers->indices.size () ;
        //for (size_t i = 0; i < inliers->indices.size (); ++i)
          //qDebug() << inliers->indices[i] << "    " << cloud->points[inliers->indices[i]].x << " "
            //                                         << cloud->points[inliers->indices[i]].y << " "
              //                                       << cloud->points[inliers->indices[i]].z ;
        _n.first=coefficients->values[0];
        _n.second.first=coefficients->values[1];
        _n.second.second=coefficients->values[2];
        return _n;
       }

}

std::pair<qreal,qreal> FittingPlane::computeDip(std::pair<float,std::pair<float,float>> _p){
    std::pair<qreal,qreal> _result ={800,-3};
    qreal x=static_cast<qreal>(_p.first);
    qreal y=static_cast<qreal>(_p.second.first);
    qreal z=static_cast<qreal>(_p.second.second);
    if(x != -3){
        if(x == 0.0 && y == 0.0) { // Traza horizontal
            _result.first = 0;
            _result.second= 0;
            return _result;
        }
        // Calculamos Dip
        _result.first = qAtan(qSqrt((x* x) + (y * y)) / z);
        _result.first = (_result.first * 180) / M_PI;
        // Calculamos dipDirection
        if( y!= 0.0 ){
            _result.second= qAtan(x / y);
            _result.second = (_result.second * 180) / M_PI;
        }else{
            if(x<0.0){
                _result.second = -90;
            }else{
                _result.second = 90;
            }
        }
        if(y<0.0){
            _result.second = 180 + _result.second;
        }else{
            if(x<0.0){
               _result.second = 360 +_result.second;
            }
        }
    }
    return _result;
}
std::pair<qreal,qreal> FittingPlane::computeStereoplotPosition(std::vector<pcl::PointXYZ> & _vec ){
   std::pair<qreal,qreal> _p = {-3,-3};
   std::pair<qreal,qreal> dip = computeDip(planeCalc(_vec));
   if(dip.first != 800){
       qreal z1 = -(qSin((90 - dip.first) * (M_PI/ 180)));
       qreal x1 = qCos((90 - dip.first) * (M_PI / 180)) * qCos((dip.second- 180) * (M_PI / 180));
       qreal y1 = qCos((90 - dip.first) * (M_PI / 180)) * qSin((dip.second - 180) * (M_PI / 180));
       _p.first = 1 * (y1 * qSqrt(1 / (1 - z1)));
       _p.second = -1 * (x1 * qSqrt(1 / (1 - z1)));
   }

   return _p;
}
