#ifndef BLAZING_SUN_PLAYER_H
#define BLAZING_SUN_PLAYER_H

#include "Character.h"

class Player : public Character
{
private:
public:
    virtual bool collides (const nsInterfaces::Collidable & other) const noexcept;
    void serialise   ();
    void deserialise ();
    void onCreate    ();
    void onUpdate    ();
    void update      ();
    void render      ();

    ~Player () { };
};

#endif //BLAZING_SUN_PLAYER_H
