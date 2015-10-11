//
// Created by Pierre-Antoine on 10/10/2015.
//

#include "Collider.h"
#include <vector>

using nsUtil::vector3f;
using nsEngine::Polygon;
using nsEngine::Collider;
using nsEngine::Collider_Comparator;


Polygon::Polygon (std::vector<vector3f> ppoints) : points (ppoints)
{
    for (vector3f p : ppoints)
    {
        center = center + p;
    }
    center = center / ppoints.size();
}

Polygon::~Polygon ()
{
}

bool Collider_Comparator::operator () (const Polygon & first, const Polygon & sec) const noexcept
{
    return false;
}
