//
// Created by Pierre-Antoine on 08/08/2015.
//

#pragma once

#include <memory>
#include <vector>

#include "../../Engine/Movement.h"
#include "Collidable.h"
#include "../Movement.h"

namespace nsInterfaces
{
    class Movable : public Collidable
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