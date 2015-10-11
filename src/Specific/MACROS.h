//
// Created by Pierre-Antoine on 11/10/2015.
//

#pragma once
//define a type for the coordinates : default float
#define COORD_TYPE float


//define if the game will be in 2D or not
#define D2

#ifdef D2
    #define DIMM(a)
    #define DIMMC(a)

#else
    #define D3
    #define DIMM(a) a
    #define DIMMC(a) , a
#endif

