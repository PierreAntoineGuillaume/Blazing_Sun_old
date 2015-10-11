//
// Created by Pierre-Antoine on 08/08/2015.
//

#include "Movement.h"

#include <cmath>

using namespace nsEngine;
using nsUtil::vector3U;

Movement::Movement()
{
    maximum_speed.x = 4;
    maximum_speed.y = 4;
    DIMM(maximum_speed.z = 4;)
}

Movement::Movement (vector3U p_maximum_speed) : maximum_speed (p_maximum_speed)
{

}

void Movement::append (vector3U pspeed) noexcept
{
    speed = speed + pspeed;
    if (speed.x > maximum_speed.x)
        speed.x = maximum_speed.x;
    if (speed.y > maximum_speed.y)
        speed.y = maximum_speed.y;
    DIMM(if (speed.z > maximum_speed.z)
        speed.z = maximum_speed.z;)
}
void Movement::change_maximum_speed_to (vector3U p_maximum_speed)
{
    maximum_speed = p_maximum_speed;
}

void Movement::change_deceleration_to (vector3U p_deceleration)
{
    deceleration = p_deceleration;
}

void Movement::update (void) noexcept
{
    //must be called after moving in move function

    speed = speed - deceleration;

    const float zero = 0.1f;

    if (std::abs(speed.x) < zero)
        speed.x = 0;
    if (std::abs(speed.y) < zero)
        speed.y = 0;
    DIMM(if (std::abs(speed.z) < zero)
        speed.z = 0;)
}

vector3U Movement::variation () const noexcept
{
    return speed;
}
