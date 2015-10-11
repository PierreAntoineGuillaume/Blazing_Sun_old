//
// Created by Pierre-Antoine on 07/08/2015.
//

#include "ResourceManager.h"
#include <iostream> //cout

using namespace nsRS;
using namespace std;

ResourceManager::ResourceManager ()
{
}

ResourceManager::~ResourceManager ()
{
}

ResourceManager * ResourceManager::Instance ()
{
    static ResourceManager instance;
    return &instance;
}

//void ResourceManager::linkGameObjectToRessource (GameObject & go) {}
