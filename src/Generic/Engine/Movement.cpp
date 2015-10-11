//
// Created by Pierre-Antoine on 08/08/2015.
//

#include "Movement.h"

using namespace nsEngine;

Movement::Movement()
{
    maximum_speed = 4;
}

Movement::Movement (float p_maximum_speed) : maximum_speed (p_maximum_speed)
{

}

void Movement::append (float p_vertical, float p_horizontal) noexcept
{
    vertical_speed += p_vertical;
    if (vertical_speed > maximum_speed)
        vertical_speed = maximum_speed;
    horizontal_speed += p_horizontal;
    if (horizontal_speed > maximum_speed)
        horizontal_speed = maximum_speed;
}
void Movement::change_maximum_speed_to (float p_maximum_speed)
{
    maximum_speed = p_maximum_speed;
}

void Movement::change_deceleration_to (float p_deceleration)
{
    deceleration = p_deceleration;
}

void Movement::update (void) noexcept
{
    //must be called after moving in move function

    horizontal_speed -= deceleration;
    if (horizontal_speed < 0)
        horizontal_speed = 0;
    vertical_speed -= deceleration;
    if (vertical_speed < 0)
        vertical_speed = 0;
}

float Movement::horizontal_variation () const noexcept
{
    return horizontal_speed;
}

float Movement::vertical_variation () const noexcept
{
    return vertical_speed;
}

void Movement::try_movement_on_collidable (const nsInterfaces::Collidable & col)
{

}
