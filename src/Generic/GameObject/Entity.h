#ifndef BLAZING_SUN_ENTITY_H
#define BLAZING_SUN_ENTITY_H

#include "GameObject.h"
#include "../Engine/Interfaces/Collidable.h"

class Entity : public GameObject, public nsInterfaces::Collidable
{
private:
public:
    void serialise   ();
    void deserialise ();
    void onCreate    ();
    void onUpdate    ();
    void update      ();
    void render      ();

    ~Entity () { };
};

#endif //BLAZING_SUN_ENTITY_H
