//
// Created by Pierre-Antoine on 08/08/2015.
//

#pragma once

#include "../Utility/Typedef.hpp"
#include "../Utility/vector3.h"

namespace nsEngine
{
    

    /**/

    class Collider_Comparator;

    class Collider
    {
        friend class Collider_Comparator;
    private:
    public:

        Collider () {}
        virtual ~Collider () noexcept {}

        virtual Collider * clone () noexcept = 0;

        virtual void move (const nsUtil::vector3 & vect) noexcept = 0;

        //TODO
        virtual void rotate () noexcept {}
    protected:
        nsUtil::vector3 center = nsUtil::vector3();
    };

    /**/
    class Polygon : public Collider
    {
        friend class Collider_Comparator;
    private:
        std::vector<nsUtil::vector3> points;
    public:

        Polygon (std::vector<nsUtil::vector3> ppoints);
        virtual ~Polygon () noexcept;
    };

    class Collider_Comparator
    {
    public:
        bool operator()(const Polygon & first,const Polygon & sec) const noexcept;

    };


/**/
}