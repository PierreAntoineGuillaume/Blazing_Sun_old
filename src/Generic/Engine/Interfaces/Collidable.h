//
// Created by Pierre-Antoine on 08/08/2015.
//

#ifndef BLAZING_SUN_COLLIDABLE_H
#define BLAZING_SUN_COLLIDABLE_H


#include "../Collider.h"

namespace nsInterfaces
{
    class Collidable
    {

    protected:
        nsEngine::Collider * col {nullptr};
    public:
        virtual bool collides (const Collidable & other) const noexcept = 0;
        virtual ~Collidable () { delete col; }

    };
}



typedef std::unique_ptr<nsInterfaces::Collidable>   uptCollidable;
typedef std::shared_ptr<nsInterfaces::Collidable>   sptCollidable;
typedef std::vector<sptCollidable>                  CollidableVector;


#endif //BLAZING_SUN_COLLIDABLE_H
