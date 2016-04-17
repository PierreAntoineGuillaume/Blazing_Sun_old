//
// Created by Pierre-Antoine on 08/08/2015.
//
#pragma once

#include <typeinfo> //serialisation

#include "../ResourceManager/Animator.h"
#include "../Utility/Typedef.hpp"



class GameObject
{
private:
public:
    virtual void serialise   () = 0;
    virtual void deserialise () = 0;
    virtual void onCreate    () = 0;
    virtual void onUpdate    () = 0;
    virtual void update      () = 0;
    virtual void render      () = 0;

    explicit virtual operator TypeInfoRef  () const noexcept;

    virtual ~GameObject () throw() { delete anim; }
protected:
    Animator* anim;
};