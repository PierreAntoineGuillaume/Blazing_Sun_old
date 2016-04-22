//
// Created by Pierre-Antoine on 06/01/2016.
//

#pragma once

//

#include "Resource.h"

namespace nsRS
{

    class CompositeResource : public Resource
    {
    public:
        CompositeResource ();
        virtual void Load () override;
    private:

    protected:
    };

}
//
