//
// Created by Pierre-Antoine on 07/08/2015.
//
#pragma once

#include <memory> //smart Pointers
#include <vector>
#include <unordered_map>
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "../Utility/Typedef.hpp"
#include "../Utility/TypeComparisonStruct.hpp"
#include "../GameObject/GameObject.h"

namespace nsRS
{
    class ResourceManager
    {
    private:
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //Singleton;
        ResourceManager& operator= (const ResourceManager& ) = default;
        ResourceManager (const ResourceManager&) = default;

        //std::unordered_map<TypeInfoRef, nsComparisonStruct::Hasher, nsComparisonStruct::EqualTo> type_map;
        ~ResourceManager ();
        ResourceManager();



    public:
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //Constructor Via Singleton;
        static ResourceManager * Instance ();
    };
} //nsEngine