//
// Created by Pierre-Antoine on 08/08/2015.
//

#pragma once


#include <vector>
#include "SFML/Graphics/Texture.hpp"
#include "../Utility/Typedef.hpp"

class Animator
{
public:
    virtual void setSpritesLoop (std::vector<std::vector<std::pair<sf::Texture,byte_t>>> & newHolder) = 0;
    virtual void update () noexcept = 0;
    virtual void render () const noexcept = 0;

    virtual ~Animator () {}
private:
    std::vector<std::vector<std::pair<sf::Texture,byte_t>>> textureLoops;
protected:
};