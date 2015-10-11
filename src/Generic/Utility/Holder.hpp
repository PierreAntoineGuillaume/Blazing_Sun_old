//
// Created by Pierre-Antoine on 11/10/2015.
//

#pragma once

namespace nsUtil
{
    template<class T>
    class Holder
    {
        T val;
        T* temporary;
    public:

        void store (const T value) noexcept;
        void release() noexcept;

        operator T & () noexcept;

        Holder ();
        Holder (const T & val) noexcept;

        ~Holder ();

    };

    template <class T>
    void Holder<T>::store(const T value) noexcept
    {
        if (temporary)
            delete temporary;
        temporary = new T(value);
    }

    template <class T>
    void Holder<T>::release () noexcept
    {
        if (temporary)
        {
            delete temporary;
            temporary = nullptr;
        }
    }

    template <class T>
    Holder<T>::operator T & () noexcept
    {
        if (temporary)
            return *temporary;
        else
            return val;
    }

    template <class T>
    Holder<T>::Holder () : val (T())
    {

    }

    template <class T>
    Holder<T>::Holder (const T & val) : Holder<T>::val (val)
    {

    }

    template <class T>
    Holder<T>::~Holder ()
    {
        if (temporary)
            delete temporary;
        temporary = nullptr;
    }

}