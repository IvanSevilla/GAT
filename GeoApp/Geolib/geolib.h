#ifndef GEOLIB_H
#define GEOLIB_H

#include "geolib_global.h"

class GEOLIBSHARED_EXPORT Geolib
{

public:
    Geolib();
    void LoadProject(string path);
    void ReadFile(string path);
    void ReadImage(string path);
    void ReadMatrix(string path);
    void ReadTif(string path);
    glm::vec3 DotPCCalculus(glm::vec2 point);
    glm::vec2 LensCorrection(glm::vec2 point);
};

#endif // GEOLIB_H
