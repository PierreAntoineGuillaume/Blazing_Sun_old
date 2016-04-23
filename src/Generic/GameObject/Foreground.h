#ifndef BLAZING_SUN_FOREGROUND_H
#define BLAZING_SUN_FOREGROUND_H

#include "Decoration.h"

class Foreground : public Decoration
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
