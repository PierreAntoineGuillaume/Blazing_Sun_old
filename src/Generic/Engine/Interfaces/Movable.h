//
// Created by Pierre-Antoine on 08/08/2015.
//

#ifndef BLAZING_SUN_MOVABLE_H
#define BLAZING_SUN_MOVABLE_H

#include <memory>
#include <vector>

#include "../../Engine/Movement.h"

namespace nsInterfaces
{
    class Movable
    {
    public:
        virtual void move () noexcept = 0;
        virtual ~Movable () {}
    protected:
        nsEngine::Movement* mov;
    };
}

typedef std::unique_ptr<nsInterfaces::Movable>      uptMovable;
typedef std::shared_ptr<nsInterfaces::Movable>      sptMovable;
typedef std::vector<sptMovable>                     MovableVector;




#endif //BLAZING_SUN_MOVABLE_H
