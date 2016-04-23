#include"GameObjectFactory.h"
#include "../GameObject/Player.h"
#include "../GameObject/Interface.h"
#include "../GameObject/Character.h"
#include "../GameObject/Entity.h"
#include "../GameObject/Decoration.h"
#include "../GameObject/Foreground.h"



GameObject *GameObjectFactory::createGameObject(GO object)
{
    GameObject *G = NULL;
    switch (object)
    {
        case PLAYER:
            G = new Player();
            break;
        case CHARACTER:
            G = new Character();
            break;
        case INTERFACE:
            G = new Interface();
            break;
        case ENTITY:
            G = new Entity();
            break;
        case DECORATION:
            G = new Decoration();
        case FOREGROUND:
            G = new Foreground();
            break;
        default:
            G = NULL;
            break;
    }
    return G;
}