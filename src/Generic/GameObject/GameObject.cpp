//
// Created by Pierre-Antoine on 08/08/2015.
//

#include "GameObject.h"

GameObject::operator TypeInfoRef () const noexcept
{
    return typeid (*this);
}
