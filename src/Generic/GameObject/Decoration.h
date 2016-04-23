#ifndef BLAZING_SUN_DECORATION_H
#define BLAZING_SUN_DECORATION_H

#include "GameObject.h"
#include "../Engine/Interfaces/Collidable.h"

class Decoration : public GameObject
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

    ~Decoration () { };
};

#endif //BLAZING_SUN_DECORATION_H
