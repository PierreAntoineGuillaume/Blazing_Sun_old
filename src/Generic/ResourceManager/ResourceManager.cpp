//
// Created by Pierre-Antoine on 07/08/2015.
//

#include "ResourceManager.h"
#include <iostream> //cout

using namespace nsRS;
using namespace std;

ResourceManager::ResourceManager ()
{
    cout << "Construction" << endl;
}

ResourceManager::~ResourceManager ()
{
    cout << "Destruction" << endl;
}

ResourceManager * ResourceManager::Instance ()
{
    static ResourceManager instance;
    return &instance;
}

void ResourceManager::linkGameObjectToRessource (GameObject & go, const nsInformation::InformationHolder & provider)
{

}
