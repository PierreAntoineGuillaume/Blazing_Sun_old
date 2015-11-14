//
// Created by Pierre-Antoine on 10/10/2015.
//

#include "Collider.h"
#include <vector>

using nsUtil::stdpoint;
using nsEngine::Polygon;
using nsEngine::Collider;
using nsEngine::Collider_Comparator;


Polygon::Polygon (nsUtil::stdpolygon ppoints) : points (ppoints)
{

}

Polygon::~Polygon ()
{
}

bool Collider_Comparator::operator () (const Polygon & first, const Polygon & sec) const noexcept
{
    return false;
}
