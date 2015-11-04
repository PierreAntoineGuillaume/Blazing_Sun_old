//
// Created by Pierre-Antoine on 08/08/2015.
//

#ifndef BLAZING_SUN_ANIMATOR_H
#define BLAZING_SUN_ANIMATOR_H


#include <vector>
#ifdef GRENABLED
    #include "SFML/Graphics/Texture.hpp"
#endif //GRENABLED
#include "../Utility/Typedef.hpp"

class Animator
{
public:
#ifdef GRENABLED
virtual void setSpritesLoop (std::vector<std::vector<std::pair<sf::Texture,byte_t>>> & newHolder) = 0;
#endif
    virtual void update () = 0;
    virtual void render () = 0;
private:
#ifdef GRENABLED
    std::vector<std::vector<std::pair<sf::Texture,byte_t>>> textureLoops;
#endif //GRENABLED
protected:
};


#endif //BLAZING_SUN_ANIMATOR_H
