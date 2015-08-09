//
// Created by Pierre-Antoine on 07/08/2015.
//
#include <memory> //smart Pointers
#include <vector>
#include <unordered_map>

#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "../Utility/Typedef.hpp"
#include "../Utility/TypeComparisonStruct.hpp"
#include "../GameObject/GameObject.h"
#include "Information/FilePath.h"
#include "Information/InformationHolder.h"


#ifndef BLAZING_SUN_RESOURCEMANAGER_H
#define BLAZING_SUN_RESOURCEMANAGER_H
namespace nsRS
{
    class ResourceManager
    {
    private:
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //Singleton;
        ResourceManager& operator= (const ResourceManager& ){}
        ResourceManager (const ResourceManager&) {};

        std::unordered_map<TypeInfoRef, nsInformation::InformationHolder, nsComparisonStruct::Hasher, nsComparisonStruct::EqualTo> type_map;
        ~ResourceManager ();
        ResourceManager();



    public:
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //Constructor Via Singleton;
        static ResourceManager * Instance ();
        void linkGameObjectToRessource (GameObject & go, const nsInformation::InformationHolder & provider);
    };
} //nsEngine

#endif //BLAZING_SUN_RESOURCEMANAGER_H
