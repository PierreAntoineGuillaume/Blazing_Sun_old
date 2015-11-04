//
// Created by Pierre-Antoine on 08/08/2015.
//

#include "Movement.h"

#include <cmath>

using namespace nsEngine;
using nsUtil::stdpoint;

Movement::Movement()
{
    for (unsigned char i {0}; i < stdpoint::dimension;++i)
        maximum_speed[i] = 4;

}

Movement::Movement (stdpoint p_maximum_speed) : maximum_speed (p_maximum_speed)
{

}

void Movement::append (stdpoint pspeed) noexcept
{
    speed = speed + pspeed;
    for (unsigned char i {0}; i < stdpoint::dimension;++i)
    {
        if (speed[i] > maximum_speed[i])
            speed[i] = maximum_speed[i];
    }
}
void Movement::change_maximum_speed_to (stdpoint p_maximum_speed)
{
    maximum_speed = p_maximum_speed;
}

void Movement::change_deceleration_to (stdpoint p_deceleration)
{
    deceleration = p_deceleration;
}

void Movement::update (void) noexcept
{
    //must be called after moving in move function

    speed = speed - deceleration;

    const stdpoint::value_type zero = stdpoint::value_type(0.1f);

    for (unsigned char i {0}; i < stdpoint::dimension;++i)
        if (std::abs(speed[i]) < zero)
            speed[i] = 0;
}

stdpoint Movement::variation () const noexcept
{
    return speed;
}
