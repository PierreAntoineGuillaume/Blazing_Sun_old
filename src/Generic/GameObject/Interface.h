#ifndef BLAZING_SUN_INTERFACE_H
#define BLAZING_SUN_INTERFACE_H

#include "GameObject.h"

class Interface : public GameObject
{
private:
public:
    void serialise   ();
    void deserialise ();
    void onCreate    ();
    void onUpdate    ();
    void update      ();
    void render      ();

    ~Interface () { };
};

#endif //BLAZING_SUN_INTERFACE_H
