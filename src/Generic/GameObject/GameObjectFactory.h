#ifndef BLAZING_SUN_GAMEOBJECTFACTORY_H
#define BLAZING_SUN_GAMEOBJECTFACTORY_H

#include "GameObject.h"

class GameObjectFactory
{
private:
public:
    enum GO {PLAYER, CHARACTER, DECORATION, ENTITY, FOREGROUND, INTERFACE};
    //GameObjectFactory();
    GameObject *createGameObject(GO objet);
};

#endif //BLAZING_SUN_GAMEOBJECTFACTORY_H
