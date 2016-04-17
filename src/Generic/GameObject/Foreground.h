#ifndef BLAZING_SUN_FOREGROUND_H
#define BLAZING_SUN_FOREGROUND_H

#include "GameObject.h"

class Foreground : public GameObject
{
private:
public:
    void serialise   ();
    void deserialise ();
    void onCreate    ();
    void onUpdate    ();
    void update      ();
    void render      ();

    ~Foreground () { };
};

#endif //BLAZING_SUN_FOREGROUND_H
