//
// Created by Pierre-Antoine on 11/10/2015.
//



#pragma once

#include "../../Specific/MACROS.h"
#include <type_traits>
#include <csignal>

namespace nsUtil
{
    namespace nsTypes
    {


    }

    template <typename T,unsigned char D>
    class geometric_point
    {
    private:
        T p [D];

    public:

        typedef T value_type;
        static const unsigned char dimension = D;

        geometric_point (std::initializer_list<T> initializer_list);
        geometric_point ();
        ~geometric_point ();
        T& operator[](const size_t & index) noexcept;
        geometric_point operator+ (const geometric_point & other) const noexcept;
        geometric_point operator- (const geometric_point & other) const noexcept;
        geometric_point operator* (unsigned number) const noexcept;
        geometric_point operator/ (unsigned number) const noexcept;
        void operator= (const geometric_point & other) noexcept;

    };

    /**
     * Constructors
     */

    template <typename T,unsigned char D>
    geometric_point<T,D>::geometric_point (std::initializer_list<T> initializer_list)
    {
        static_assert (std::is_scalar<T>::value,"The template type parameter has to be scalar");
        //static_assert (sizeof(initializer_list) / sizeof(T) == D,"You can either use a null constructor or use a c array of size specified in template ");

        std::copy (initializer_list.begin (),initializer_list.end(),p);
    }

    template <typename T,unsigned char D>
    geometric_point<T,D>::geometric_point ()
    {
        static_assert (std::is_scalar<T>::value,"The template type parameter has to be scalar");
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

    template <typename T,unsigned char D>
    nsUtil::geometric_point<T,D>::~geometric_point ()
    {

    }

    typedef geometric_point<float,2> geometric_pointfa;
    typedef geometric_point<int,2> geometric_pointi;
    typedef geometric_point<COORD_TYPE,COORD_NUMBER> stdpoint;
}//nsUtil