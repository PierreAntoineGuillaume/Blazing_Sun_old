//
// Created by Pierre-Antoine on 06/01/2016.
//

#pragma once

//

#include "Ressource.h"

namespace nsRS
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
