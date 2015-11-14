//
// Created by Pierre-Antoine on 14/11/2015.
//

#pragma once

#include "point.hpp"


//

namespace nsUtil
{

    template <typename T, unsigned char D>
    class polygon
    {
    public:

        //deleted default constructor
        polygon () = delete;

        polygon (unsigned char size);
        polygon (std::initializer_list<nsUtil::geometric_point<T,D>> initializer_list);
        polygon (const polygon & rvalue);
        ~polygon();
        void move (const nsUtil::geometric_point<T,D> vector);
    private:
        std::vector<geometric_point<T,D>> points;
    protected:
    };

    typedef polygon<stdpoint::value_type,stdpoint::dimension> stdpolygon;
}//nsUtil

//constructors
/** /
template <typename T,unsigned char D>
nsUtil::polygon<T,D>::polygon()
{

}
/**/
template <typename T,unsigned char D>
nsUtil::polygon<T,D>::polygon(unsigned char size)
{
    points.resize(size);
}

template <typename T,unsigned char D>
nsUtil::polygon<T,D>::polygon(const polygon<T,D> & rvalue)
{
    points = rvalue.points;
}

template <typename T,unsigned char D>
nsUtil::polygon<T,D>::polygon(std::initializer_list<nsUtil::geometric_point<T,D>> initializer_list)
{
    points = std::vector<geometric_point<T,D>>(initializer_list);
}

//destructor
template <typename T,unsigned char D>
nsUtil::polygon<T,D>::~polygon()
{
}


//functions
template <typename T,unsigned char D>
void nsUtil::polygon<T,D>::move(const nsUtil::geometric_point<T,D> vector)
{
    //todo

}

//
