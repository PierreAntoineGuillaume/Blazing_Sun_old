//
// Created by Pierre-Antoine on 11/10/2015.
//



#pragma once

#include "../../Specific/MACROS.h"

#define TEMPL template <typename T,unsigned char D>


namespace nsUtil
{

    TEMPL
    class pvector
    {
    private:
        T p [D];
    public:

        typedef T value_type;
        static const unsigned char dimension = D;

        pvector ();
        //pvector ();
        ~pvector ();
        T& operator[](const size_t & index) noexcept;
        pvector operator+ (const pvector & other) const noexcept;
        pvector operator- (const pvector & other) const noexcept;
        pvector operator* (unsigned number) const noexcept;
        pvector operator/ (unsigned number) const noexcept;
        void operator= (const pvector & other) noexcept;

    };

    TEMPL
    T& nsUtil::pvector<T,D>::operator[](const size_t & index) noexcept
    {
        return p[index];
    }

    TEMPL
    nsUtil::pvector<T,D> nsUtil::pvector<T,D>::operator - (const nsUtil::pvector<T,D> & other) const noexcept
    {
        nsUtil::pvector<T,D> t = *this;
        for(unsigned char i {0}; i < D;++i)
            t.p[i] -= other.p[i];
        return t;
    }

    TEMPL
    nsUtil::pvector<T,D>::pvector ()

    {

    }
    /** /
    TEMPL
    nsUtil::pvector<T,D>::pvector ()
    {

    }
    /**/
    TEMPL
    nsUtil::pvector<T,D> nsUtil::pvector<T,D>::operator + (const nsUtil::pvector<T,D> & other) const noexcept
    {
        nsUtil::pvector<T,D> t = *this;
        for(unsigned char i {0}; i < D;++i)
            t.p[i] += other.p[i];
        return t;
    }

    TEMPL
    nsUtil::pvector<T,D> nsUtil::pvector<T,D>::operator * (unsigned number) const noexcept
    {
        nsUtil::pvector<T,D> t = *this;
        for(unsigned char i {0}; i < D;++i)
            t.p[i] *= number;
        return t;
    }

    TEMPL
    nsUtil::pvector<T,D> nsUtil::pvector<T,D>::operator / (unsigned number) const noexcept
    {
        nsUtil::pvector<T,D> t = *this;
        for(unsigned char i {0}; i < D;++i)
            t.p[i] /= number;
        return t;
    }

    TEMPL
    void nsUtil::pvector<T,D>::operator = (const nsUtil::pvector<T,D> & other) noexcept
    {
        for(unsigned char i {0}; i < D;++i)
            this->p[i] = other.p[i];
    }

    TEMPL
    nsUtil::pvector<T,D>::~pvector ()
    {

    }

    typedef pvector<float,2> pvectorfa;
    typedef pvector<int,2> pvectori;
    typedef pvector<COORD_TYPE,COORD_NUMBER> vector3U;

}//nsUtil


#undef TEMPL