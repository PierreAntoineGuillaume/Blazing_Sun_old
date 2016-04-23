#include"GameObjectFactory.h"
#include "../GameObject/Player.h"
#include "../GameObject/Decoration.h"
#include "../GameObject/Foreground.h"
#include "../Utility/exception/invalid_gameobject.h"


GameObject *GameObjectFactory::createGameObject(GO object)
{
    GameObject *G = NULL;
    switch (object)
    {
        case PLAYER:
            G = new Player();
            break;
        case FOREGROUND:
            G = new Foreground();
            break;
        default:
            throw invalid_gameobject ();
            G = NULL;
            break;
    }
    return G;
}