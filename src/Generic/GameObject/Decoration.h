#ifndef BLAZING_SUN_DECORATION_H
#define BLAZING_SUN_DECORATION_H

#include "GameObject.h"

class Decoration : public GameObject
{
private:
public:
    void serialise   ();
    void deserialise ();
    void onCreate    ();
    void onUpdate    ();
    void update      ();
    void render      ();

    ~Decoration () { };
};

#endif //BLAZING_SUN_DECORATION_H
