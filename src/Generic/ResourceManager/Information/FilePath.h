//
// Created by Pierre-Antoine on 09/08/2015.
//

#ifndef BLAZING_SUN_FILEPATH_H
#define BLAZING_SUN_FILEPATH_H

#include "../../Engine/Collider.h"
#include "../../Utility/Typedef.hpp"

#include "../../Utility/TypeComparisonStruct.hpp"

#include "SFML/Graphics/Rect.hpp"

namespace nsInformation
{
    struct FilePath
    {
        sf::IntRect rect;
        std::string path_to_file;
        byte_t index;
        byte_t duration;
    };
}

#endif //BLAZING_SUN_FILEPATH_H
