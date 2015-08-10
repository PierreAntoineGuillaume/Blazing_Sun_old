//
// Created by Pierre-Antoine on 09/08/2015.
//

#ifndef BLAZING_SUN_INFORMATIONHOLDER_H
#define BLAZING_SUN_INFORMATIONHOLDER_H

#include <vector>


#include <SFML/Graphics/Texture.hpp>
#include "FilePath.h"
#include "../Animator.h"
#include "../../Utility/Typedef.hpp"
#include "../../GameObject/GameObject.h"

namespace nsInformation
{
    class InformationHolder
    {
    public:
        void accept (Animator & an);

        InformationHolder (const GameObject & go);

        void update ();
        void update (byte_pair newFormat) noexcept;

        InformationHolder& operator << (const nsInformation::FilePath & fp) noexcept;

    private:
        std::vector<FilePath> dirs;
        std::vector<std::vector<std::pair<sf::Texture,byte_t>>> textures;
        std::string objectName;
        byte_pair format;
    };
}

#endif //BLAZING_SUN_INFORMATIONHOLDER_H
