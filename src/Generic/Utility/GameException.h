//
// Created by Pierre-Antoine on 09/08/2015.
//

#ifndef BLAZING_SUN_GAMEEXCEPTION_H
#define BLAZING_SUN_GAMEEXCEPTION_H

#include <exception>

namespace nsUtil
{
    class GameException : public std::exception
    {
    public:
        GameException operator= (const GameException&) = delete;
        virtual ~GameException () {}
    };
}

#endif //BLAZING_SUN_GAMEEXCEPTION_H
