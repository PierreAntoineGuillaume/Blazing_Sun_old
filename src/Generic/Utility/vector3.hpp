//
// Created by Pierre-Antoine on 11/10/2015.
//

#pragma once
#define TEMPL template <typename T>


namespace nsUtil
{

    TEMPL
    class vector3
    {
    public:
        T x;
        T y;
        T z;

        vector3 ();
        vector3 (T px,T py,T pz);
        ~vector3 ();

        vector3 operator+ (const vector3 & other) const noexcept;
        vector3 operator- (const vector3 & other) const noexcept;
        vector3 operator* (unsigned number) const noexcept;
        vector3 operator/ (unsigned number) const noexcept;
        void operator= (const vector3 & other) noexcept;

    };


    TEMPL
    nsUtil::vector3<T> nsUtil::vector3<T>::operator - (const nsUtil::vector3<T> & other) const noexcept
    {
        return nsUtil::vector3<T> (x -other.x, y -other.y, z-other.z);
    }

    TEMPL
    nsUtil::vector3<T>::vector3 () : x(0), y(0), z(0)
    {

    }

    TEMPL
    nsUtil::vector3<T>::vector3 (T px, T py, T pz) : x(px), y(py), z(pz)
    {

    }

    TEMPL
    nsUtil::vector3<T> nsUtil::vector3<T>::operator + (const nsUtil::vector3<T> & other) const noexcept
    {
        return nsUtil::vector3<T> (x +other.x, y +other.y, z+other.z);
    }

    TEMPL
    nsUtil::vector3<T> nsUtil::vector3<T>::operator * (unsigned number) const noexcept
    {
        return nsUtil::vector3<T> (x*number, y*number, z*number);
    }

    TEMPL
    nsUtil::vector3<T> nsUtil::vector3<T>::operator / (unsigned number) const noexcept
    {
        if (!number)
            number = 1;
        return nsUtil::vector3<T> (x/number, y/number, z/number);
    }

    TEMPL
    void nsUtil::vector3<T>::operator = (const nsUtil::vector3<T> & other) noexcept
    {
        x = other.x;
        y = other.y;
        z = other.z;
    }

    TEMPL
    nsUtil::vector3<T>::~vector3 ()
    {

    }

    typedef vector3<float> vector3f;
    typedef vector3<int> vector3i;

}//nsUtil


#undef TEMPL