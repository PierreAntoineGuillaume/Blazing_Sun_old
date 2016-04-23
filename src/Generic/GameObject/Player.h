#ifndef BLAZING_SUN_PLAYER_H
#define BLAZING_SUN_PLAYER_H

#include "Character.h"

class Player : public Character
{
private:
public:
    void serialise   ();
    void deserialise ();
    void onCreate    ();
    void onUpdate    ();
    void update      ();
    void render      ();

    ~Player () { };
};

#endif //BLAZING_SUN_PLAYER_H
