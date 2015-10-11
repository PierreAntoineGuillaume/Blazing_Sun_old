//
// Created by Pierre-Antoine on 08/08/2015.
//

#pragma once


#include "Interfaces/Collidable.h"
#include "../Utility/vector3.hpp"

namespace nsEngine
{

    class Movement
    {
    public:
        Movement ();
        Movement (float p_maximum_speed);
        void append (float p_vertical, float p_horizontal) noexcept;
        void change_maximum_speed_to (float p_maximum_speed);
        void change_deceleration_to (float p_deceleration);
        void update (void) noexcept;

        float horizontal_variation () const noexcept;
        float vertical_variation () const noexcept;

        void try_movement_on_collidable (const nsInterfaces::Collidable & col);
    private:
        nsUtil::vector3f speed;
        nsUtil::vector3f maximum_speed;
        nsUtil::vector3f deceleration = nsUtil::vector3f(1,1,0);


    protected:
    };
}