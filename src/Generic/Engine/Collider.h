//
// Created by Pierre-Antoine on 08/08/2015.
//

#ifndef BLAZING_SUN_COLLIDER_H
#define BLAZING_SUN_COLLIDER_H

#include "../Utility/Typedef.hpp"

namespace nsEngine
{
    class Collider
    {
    private:
    public:
        Collider () {}
        virtual ~Collider () noexcept {}
    protected:
    };

    class Rectangle : public Collider
    {
    public:
        Rectangle () {}
        virtual ~Rectangle () noexcept {}
    };
}

#endif //BLAZING_SUN_COLLIDER_H
