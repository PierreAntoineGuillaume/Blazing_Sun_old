//
// Created by Pierre-Antoine on 08/08/2015.
//

#include "Movement.h"

#include <cmath>

using namespace nsEngine;
using nsUtil::vector3U;

Movement::Movement()
{
    for (unsigned char i {0}; i < vector3U::dimension;++i)
        maximum_speed[i] = 4;

}

Movement::Movement (vector3U p_maximum_speed) : maximum_speed (p_maximum_speed)
{

}

void Movement::append (vector3U pspeed) noexcept
{
    speed = speed + pspeed;
    for (unsigned char i {0}; i < vector3U::dimension;++i)
    {
        if (speed[i] > maximum_speed[i])
            speed[i] = maximum_speed[i];
    }
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

    const vector3U::type zero = 0.1f;

    for (unsigned char i {0}; i < vector3U::dimension;++i)
        if (std::abs(speed[i]) < zero)
            speed[i] = 0;
}

vector3U Movement::variation () const noexcept
{
    return speed;
}
