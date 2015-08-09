//
// Created by Pierre-Antoine on 09/08/2015.
//

#ifndef BLAZING_SUN_TYPECOMPARISONSTRUCT_HPP
#define BLAZING_SUN_TYPECOMPARISONSTRUCT_HPP

#include <cstddef>
#include "Typedef.hpp"

namespace nsComparisonStruct
{
    struct Hasher
    {
        std::size_t operator () (TypeInfoRef code) const
        {
            return code.get ().hash_code ();
        }
    };

    struct EqualTo
    {
        bool operator () (TypeInfoRef lhs, TypeInfoRef rhs) const
        {
            return lhs.get () == rhs.get ();
        }
    };
    /*
    struct GenericallyComparable
    {
        virtual operator ComparisonOperator () const noexcept = 0;
    };

    struct QuickComparison
    {
        bool AgreaterThanB (const ComparisonOperator & a, const ComparisonOperator & b)
        {
            return a > b;
        }

        bool AlesserThanB (const ComparisonOperator & a, const ComparisonOperator & b)
        {
            return a < b;
        }

        bool AdifferentFromB (const ComparisonOperator & a, const ComparisonOperator & b)
        {
            return a != b;
        }

        bool AequalsB (const ComparisonOperator & a, const ComparisonOperator & b)
        {
            return a == b;
        }
    };
    */
}
#endif //BLAZING_SUN_TYPECOMPARISONSTRUCT_HPP
