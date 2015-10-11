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
        Movement (nsUtil::vector3U p_maximum_speed);
        void append (nsUtil::vector3U pspeed) noexcept;
        void change_maximum_speed_to (nsUtil::vector3U p_maximum_speed);
        void change_deceleration_to (nsUtil::vector3U p_deceleration);
        void update (void) noexcept;

        nsUtil::vector3U variation () const noexcept;

    private:
        nsUtil::vector3U speed;
        nsUtil::vector3U maximum_speed;
        nsUtil::vector3U deceleration = nsUtil::vector3U(1,1 DIMMP(1));


    protected:
    };
}