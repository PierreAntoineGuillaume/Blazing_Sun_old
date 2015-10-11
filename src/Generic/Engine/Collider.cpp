//
// Created by Pierre-Antoine on 10/10/2015.
//

#include "Collider.h"
#include <vector>


using nsUtil::vector3;


nsEngine::Polygon::Polygon (std::vector<vector3> ppoints)
{
    points = new vector3[ppoints.size()];
    unsigned int i = 0;
    for (vector3 p : ppoints)
    {
        points[i++] = p;
        center = center + p;
    }
    center = center / ppoints.size();
}

nsEngine::Polygon::~Polygon ()
{
    delete[] points;
}

