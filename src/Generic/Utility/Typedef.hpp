//
// Created by Pierre-Antoine on 08/08/2015.
//


#pragma once

#include <cstddef>
#include <cstdint>

#include <memory>
#include <vector>
#include <typeinfo>

typedef std::reference_wrapper<const std::type_info> TypeInfoRef;
typedef uint8_t byte_t;
typedef std::pair<byte_t,byte_t> byte_pair;