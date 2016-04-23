#include "Decoration.h"
#include <iostream>

void::Decoration::serialise()
{

}

void::Decoration::deserialise()
{

}

void::Decoration::onCreate()
{
    std::cout << "decoration created" << std::endl;
}

void::Decoration::onUpdate()
{

}

void::Decoration::update()
{

}

void::Decoration::render()
{

}

bool Decoration::collides (const nsInterfaces::Collidable & other) const noexcept
{
    return false;
}

