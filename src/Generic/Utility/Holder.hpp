//
// Created by Pierre-Antoine on 11/10/2015.
//

#pragma once

namespace nsUtil
{
    template<class T>
    class Holder
    {
        typedef T value_type;
        T val;
        T* temporary;
    public:

        void push (const T & value) noexcept;
        void overwrite  () noexcept;
        void pop () noexcept;
        void replicate () noexcept;

        typename std::add_lvalue_reference<T>::type operator *() noexcept;

        Holder ();
        Holder (const T & val) noexcept;

        ~Holder ();

    };

    template <class T>
    void Holder<T>::push(const T & value) noexcept
    {
        if (temporary)
            delete temporary;
        temporary = new T(value);
    }

    template <class T>
    void Holder<T>::overwrite () noexcept
    {
        if (!temporary)
            return;
        val = *temporary;
        delete temporary;
        temporary = nullptr;

    }

    template <class T>
    void Holder<T>::pop () noexcept
    {
        if (temporary)
        {
            delete temporary;
            temporary = nullptr;
        }
    }

    template <typename T>
    void Holder<T>::replicate () noexcept
    {
        push (val);
    }

    template <class T>
    typename std::add_lvalue_reference<T>::type Holder<T>::operator *() noexcept
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
    Holder<T>::Holder (const T & pval) noexcept : val (pval)
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