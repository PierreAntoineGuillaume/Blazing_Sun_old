#ifndef BLAZING_SUN_ENTITY_H
#define BLAZING_SUN_ENTITY_H

#include "GameObject.h"

class Entity : public GameObject
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
