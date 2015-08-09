//
// Created by Pierre-Antoine on 08/08/2015.
//

#ifndef BLAZING_SUN_GAMEOBJECT_H
#define BLAZING_SUN_GAMEOBJECT_H

#include <typeinfo> //serialisation

#include "../ResourceManager/Animator.h"
#include "../Utility/Typedef.hpp"



class GameObject
{
private:
public:
    virtual void serialise   () const noexcept = 0;
    virtual void deserialise () noexcept = 0;
    virtual void update      () noexcept = 0;
    virtual void render      () noexcept = 0;

    explicit virtual operator TypeInfoRef  () const noexcept;

    virtual ~GameObject () { delete anim; }
protected:
    Animator* anim;
};


#endif //BLAZING_SUN_GAMEOBJECT_H
