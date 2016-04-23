
#ifndef BLAZING_SUN_CHARACTER_H
#define BLAZING_SUN_CHARACTER_H


#include "Entity.h"

class Character : public Entity
{
private:
public:
    void serialise   ();
    void deserialise ();
    void onCreate    ();
    void onUpdate    ();
    void update      ();
    void render      ();

    ~Character () { };
};

#endif //BLAZING_SUN_CHARACTER_H
