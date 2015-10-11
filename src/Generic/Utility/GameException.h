//
// Created by Pierre-Antoine on 09/08/2015.
//

#pragma once

#include <exception>

namespace nsUtil
{
    class GameException : public std::exception
    {
    public:
        virtual ~GameException () {}
    };
}