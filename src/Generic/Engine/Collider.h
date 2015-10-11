//
// Created by Pierre-Antoine on 08/08/2015.
//

#pragma once

#include "../Utility/Typedef.hpp"
#include "../Utility/vector3.hpp"

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


        virtual void attemptMove(const nsUtil::vector3U & vect) noexcept = 0;
        virtual void move () noexcept = 0;

        //TODO
        virtual void attemptRotation () noexcept {}
        //TODO
        virtual void rotate () noexcept {}

    protected:
        nsUtil::vector3U center = nsUtil::vector3U();
    };

    /**/
    class Polygon : public Collider
    {
        friend class Collider_Comparator;
    private:
        std::vector<nsUtil::vector3U> points;
    public:

        Polygon (std::vector<nsUtil::vector3U> ppoints);
        virtual ~Polygon () noexcept;
    };

    class Collider_Comparator
    {
    public:
        bool operator()(const Polygon & first,const Polygon & sec) const noexcept;

    };


/**/
}