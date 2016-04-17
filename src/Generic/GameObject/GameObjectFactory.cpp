#include"GameObjectFactory.h"
#include "Player.h"
#include "Interface.h"
#include "Character.h"
#include "Entity.h"
#include "Decoration.h"
#include "Foreground.h"



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