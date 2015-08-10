//
// Created by Pierre-Antoine on 09/08/2015.
//

#ifndef BLAZING_SUN_FILEPATH_H
#define BLAZING_SUN_FILEPATH_H

#include <queue>


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

    class MacroFilePath
    {
    private:
        std::queue<sf::IntRect> rects;
        std::string path_to_file;
        std::queue<byte_t> indexes;
        std::queue<byte_t> durations;

    public:
        MacroFilePath(std::string pPath_to_file);
        MacroFilePath& operator<< (const sf::IntRect & box,byte_t index, byte_t duration);
        FilePath Pop () noexcept;
        bool empty   () const noexcept;
    };

}

#endif //BLAZING_SUN_FILEPATH_H
