//
// Created by Pierre-Antoine on 08/08/2015.
//

#pragma once

#include "../Utility/Typedef.hpp"
#include "../Utility/Holder.hpp"
#include "../Utility/point.hpp"

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


        virtual void attemptMove(const nsUtil::stdpoint & vect) noexcept = 0;
        virtual void move () noexcept = 0;

        //TODO
        virtual void attemptRotation () noexcept {}
        //TODO
        virtual void rotate () noexcept {}

    protected:
        nsUtil::stdpoint center = nsUtil::stdpoint();
    };

    /**/
    class Polygon : public Collider
    {
        friend class Collider_Comparator;
    private:
        nsUtil::Holder<std::vector<nsUtil::stdpoint>> points;
    public:

        Polygon (std::vector<nsUtil::stdpoint> ppoints);
        virtual ~Polygon () noexcept;
    };

    class Collider_Comparator
    {
    public:
        bool operator()(const Polygon & first,const Polygon & sec) const noexcept;

    };


/**/
}