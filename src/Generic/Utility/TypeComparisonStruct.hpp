//
// Created by Pierre-Antoine on 09/08/2015.
//

#pragma once

#include <cstddef>
#include "Typedef.hpp"

namespace nsComparisonStruct
{
    struct Hasher
    {
        std::size_t operator () (TypeInfoRef code) const
        {
            return code.get ().hash_code ();
        }
    };

    struct EqualTo
    {
        bool operator () (TypeInfoRef lhs, TypeInfoRef rhs) const
        {
            return lhs.get () == rhs.get ();
        }
    };
}