//
// Created by Pierre-Antoine on 06/01/2016.
//

#pragma once

//

#include "Ressource.h"

namespace
{

    class CompositeRessource : public Ressource
    {
    public:
        CompositeRessource ();
        virtual void Load () override;
    private:

    protected:
    };

}
//
