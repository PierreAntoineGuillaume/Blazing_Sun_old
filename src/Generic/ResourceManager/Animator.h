//
// Created by Pierre-Antoine on 08/08/2015.
//

#ifndef BLAZING_SUN_ANIMATOR_H
#define BLAZING_SUN_ANIMATOR_H


#include <vector>

#include "SFML/Graphics/Texture.hpp"
#include "../Utility/Typedef.hpp"

class Animator
{
public:
    virtual void setSpritesLoop (std::vector<std::vector<std::pair<sf::Texture,byte_t>>> & newHolder) = 0;
    virtual void update () = 0;
    virtual void render () = 0;
private:
    std::vector<std::vector<std::pair<sf::Texture,byte_t>>> textureLoops;
protected:
};


#endif //BLAZING_SUN_ANIMATOR_H
