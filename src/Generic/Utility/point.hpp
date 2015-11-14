//
// Created by Pierre-Antoine on 11/10/2015.
//



#pragma once

#include "../../Specific/MACROS.h"
#include <type_traits>
#include <csignal>
#include <cmath>



namespace nsUtil
{
    template <typename T,unsigned char D>
    class geometric_point
    {
    private:
        T p [D +1];
        void __construct();
    public:

        typedef T value_type;
        static const unsigned char dimension = D;

        geometric_point (std::initializer_list<T> initializer_list);
        geometric_point ();
        geometric_point (const geometric_point & rvalue);
        ~geometric_point ();
        T& operator[](const size_t & index) noexcept;
        T absolute_distance() const noexcept;

        geometric_point operator+ (const geometric_point & other) const noexcept;
        geometric_point operator- (const geometric_point & other) const noexcept;
        geometric_point operator* (unsigned number) const noexcept;
        geometric_point operator/ (unsigned number) const noexcept;


        /* Homogeneous coordinates*/

        void apply_homogenous_coordinates_multiplication (const std::array<std::array<T,D+1>,D+1> & matrix) noexcept;

        /**/

        void operator= (const geometric_point & other) noexcept;

        std::array<std::array<T,D+1>,D+1> build_translation_matrix() const noexcept;
        std::array<std::array<T,D+1>,D+1> build_rotation_matrix() const noexcept;


    };
    typedef geometric_point<COORD_TYPE,COORD_NUMBER> stdpoint;

}//nsUtil

/**
 * Constructors
 */

template <typename T,unsigned char D>
void nsUtil::geometric_point<T,D>::__construct ()
{
    static_assert(D<3 || D != 0,"Point must be in 1, 2, or 3 dimensions");
    static_assert (std::is_scalar<T>::value,"The template type parameter has to be scalar");
}

template <typename T,unsigned char D>
nsUtil::geometric_point<T,D>::geometric_point (std::initializer_list<T> initializer_list)
{
    __construct ();
    std::copy (initializer_list.begin (),initializer_list.end(),p);
    p[D] = 1;
}

template <typename T,unsigned char D>
nsUtil::geometric_point<T,D>::geometric_point ()
{
    __construct ();
    p[D] = 1;
}

template <typename T, unsigned char D>
nsUtil::geometric_point<T,D>::geometric_point (const nsUtil::geometric_point<T,D> & rvalue)
{
    __construct ();
    std::copy(rvalue.p,rvalue.p + D +1,p);
}


/**
 * Operators
 */


template <typename T,unsigned char D>
T& nsUtil::geometric_point<T,D>::operator[](const size_t & index) noexcept
{
    if (index >= D)
        std::raise (SIGSEGV);
    return p[index];
}

template <typename T,unsigned char D>
nsUtil::geometric_point<T,D> nsUtil::geometric_point<T,D>::operator - (const nsUtil::geometric_point<T,D> & other) const noexcept
{
    nsUtil::geometric_point<T,D> t = *this;
    for(unsigned char i {0}; i < D;++i)
        t.p[i] -= other.p[i];
    return t;
}



template <typename T,unsigned char D>
nsUtil::geometric_point<T,D> nsUtil::geometric_point<T,D>::operator + (const nsUtil::geometric_point<T,D> & other) const noexcept
{
    nsUtil::geometric_point<T,D> t = *this;
    for(unsigned char i {0}; i < D;++i)
        t.p[i] += other.p[i];
    return t;
}

template <typename T,unsigned char D>
nsUtil::geometric_point<T,D> nsUtil::geometric_point<T,D>::operator * (unsigned number) const noexcept
{
    nsUtil::geometric_point<T,D> t = *this;
    for(unsigned char i {0}; i < D;++i)
        t.p[i] *= number;
    return t;
}

template <typename T,unsigned char D>
nsUtil::geometric_point<T,D> nsUtil::geometric_point<T,D>::operator / (unsigned number) const noexcept
{
    nsUtil::geometric_point<T,D> t = *this;
    for(unsigned char i {0}; i < D;++i)
        t.p[i] /= number;
    return t;
}

template <typename T,unsigned char D>
void nsUtil::geometric_point<T,D>::operator = (const nsUtil::geometric_point<T,D> & other) noexcept
{
    for(unsigned char i {0}; i < D;++i)
        this->p[i] = other.p[i];
}

//Destructor
template <typename T,unsigned char D>
nsUtil::geometric_point<T,D>::~geometric_point ()
{

}

template <typename T, unsigned char D>
T nsUtil::geometric_point<T,D>::absolute_distance() const noexcept
{
    T return_val;
    for (unsigned char i = 0;i<D;++i)
        return_val += pow(p[i],2);
    return sqrt (return_val);
}


template <typename T, unsigned char D>
std::array<std::array<T,D+1>,D+1> nsUtil::geometric_point<T,D>::build_translation_matrix() const noexcept
{
    std::array<std::array<T,D+1>,D+1> ref_rvalue;
    //builds up a matrix of size D+1 square

    for (size_t i {0};i < D;++i)
    {
        ref_rvalue[i][i] = T(1);
        //fills the diagonal with 1s
        ref_rvalue[i][D] = p[i];
        //sets the right column to p[i]
    }

    ref_rvalue[D][D] = T(1);
    //sets the last element of the matrix to 1

    /** Ex : point<int,3> {5,2,3} becomes :
     *  1 0 0 5
     *  0 1 0 2
     *  0 0 1 3
     *  0 0 0 1
     *
     *
     *  or : point<float,2> {3.f,8.f} becomes :
     *  1 0 3
     *  0 1 8
     *  0 0 1
     */


    return ref_rvalue;
}

template <typename T, unsigned char D>
std::array<std::array<T,D+1>,D+1> nsUtil::geometric_point<T,D>::build_rotation_matrix() const noexcept
{

}

/* Homogeneous coordinates*/
template <typename T,unsigned char D>
void nsUtil::geometric_point<T,D>::apply_homogenous_coordinates_multiplication (const std::array<std::array<T,D+1>,D+1> & matrix)
{

}
