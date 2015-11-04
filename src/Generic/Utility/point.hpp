//
// Created by Pierre-Antoine on 11/10/2015.
//



#pragma once

#include "../../Specific/MACROS.h"
#include <cstdarg>
#include <type_traits>

namespace nsUtil
{
    namespace nsTypes
    {


    }

    template <typename T,unsigned char D>
    class point
    {
    private:
        T p [D];

    public:

        typedef T value_type;
        static const unsigned char dimension = D;

        point ();
        ~point ();
        T& operator[](const size_t & index) noexcept;
        point operator+ (const point & other) const noexcept;
        point operator- (const point & other) const noexcept;
        point operator* (unsigned number) const noexcept;
        point operator/ (unsigned number) const noexcept;
        void operator= (const point & other) noexcept;

    };

    template <typename T,unsigned char D>
    T& nsUtil::point<T,D>::operator[](const size_t & index) noexcept
    {
        return p[index];
    }

    template <typename T,unsigned char D>
    nsUtil::point<T,D> nsUtil::point<T,D>::operator - (const nsUtil::point<T,D> & other) const noexcept
    {
        nsUtil::point<T,D> t = *this;
        for(unsigned char i {0}; i < D;++i)
            t.p[i] -= other.p[i];
        return t;
    }

    template <typename T,unsigned char D>
    nsUtil::point<T,D>::point ()

    {
        static_assert (std::is_scalar<T>::value,"The template type parameter has to be scalar");
    }

    template <typename T,unsigned char D>
    nsUtil::point<T,D> nsUtil::point<T,D>::operator + (const nsUtil::point<T,D> & other) const noexcept
    {
        nsUtil::point<T,D> t = *this;
        for(unsigned char i {0}; i < D;++i)
            t.p[i] += other.p[i];
        return t;
    }

    template <typename T,unsigned char D>
    nsUtil::point<T,D> nsUtil::point<T,D>::operator * (unsigned number) const noexcept
    {
        nsUtil::point<T,D> t = *this;
        for(unsigned char i {0}; i < D;++i)
            t.p[i] *= number;
        return t;
    }

    template <typename T,unsigned char D>
    nsUtil::point<T,D> nsUtil::point<T,D>::operator / (unsigned number) const noexcept
    {
        nsUtil::point<T,D> t = *this;
        for(unsigned char i {0}; i < D;++i)
            t.p[i] /= number;
        return t;
    }

    template <typename T,unsigned char D>
    void nsUtil::point<T,D>::operator = (const nsUtil::point<T,D> & other) noexcept
    {
        for(unsigned char i {0}; i < D;++i)
            this->p[i] = other.p[i];
    }

    template <typename T,unsigned char D>
    nsUtil::point<T,D>::~point ()
    {

    }

    typedef point<float,2> pointfa;
    typedef point<int,2> pointi;
    typedef point<COORD_TYPE,COORD_NUMBER> stdpoint;

}//nsUtil