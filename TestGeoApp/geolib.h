#ifndef GEOLIB_H
#define GEOLIB_H

#define NUM_IMAGES 10
#define NUM_POINTCLOUD 2
#include "geolib_global.h"

class GEOLIBSHARED_EXPORT Geolib
{

public:
    struct Project
    {
        Project() {}
        QImage images[NUM_IMAGES];
        int Type;
        arma::field<arma::mat> matrices (); // try using arma::Cube
        arma::mat calibration ();
        arma::field<arma::mat> PointCloud ();



    };
    Geolib();
    void LoadProject(QString path);
    void ReadFile(QString path);
    void ReadImage(QString path);
    void ReadMatrix(QString path);
    void ReadTif(QString path);
    glm::vec3 DotPCCalculus(glm::vec2 point);
    glm::vec2 LensCorrection(glm::vec2 point);
};

#endif // GEOLIB_H
