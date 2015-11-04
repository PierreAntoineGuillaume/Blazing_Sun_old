//
// Created by Pierre-Antoine on 08/08/2015.
//

#pragma once


#include "Interfaces/Collidable.h"
#include "../Utility/point.hpp"

namespace nsEngine
{

    class Movement
    {
    public:
        Movement ();
        Movement (nsUtil::stdpoint p_maximum_speed);
        void append (nsUtil::stdpoint pspeed) noexcept;
        void change_maximum_speed_to (nsUtil::stdpoint p_maximum_speed);
        void change_deceleration_to (nsUtil::stdpoint p_deceleration);
        void update (void) noexcept;

        nsUtil::stdpoint variation () const noexcept;

    private:
        nsUtil::stdpoint speed;
        nsUtil::stdpoint maximum_speed;
        nsUtil::stdpoint deceleration = nsUtil::stdpoint();


    protected:
    };
}