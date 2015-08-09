//
// Created by Pierre-Antoine on 09/08/2015.
//

#include <iostream>
#include <typeinfo>
#include <cassert>

#include "InformationHolder.h"

using std::cerr;
using std::endl;

void nsInformation::InformationHolder::accept (Animator & an)
{
    an.setSpritesLoop (textures);
}

void nsInformation::InformationHolder::update ()
{
    byte_t formatSize = format.first * format.second;
    assert (dirs.size ()    < formatSize);
    std::sort (dirs.begin(),dirs.end(),[](FilePath a, FilePath b){return a.index <= b.index;});//classement croissant par index
    textures.clear();
    textures.resize (format.first);
    for (size_t i {0}, a {0}; i < format.first ;++i, ++a)
    {
        textures[i].resize (format.second);
        for (size_t j {0};j < format.second;++j,++a)
        {
            if (!textures [i][j].first.loadFromFile (dirs[a].path_to_file,dirs[a].rect))
            {
                //texture not found

            }
            else
                textures[i][j].second = dirs[a].duration;
        }
    }

}

void nsInformation::InformationHolder::update (byte_pair newFormat) noexcept
{
    if (format.first && format.second)
        format = newFormat;
}


nsInformation::InformationHolder::InformationHolder (const GameObject & go) :
        objectName  (typeid (go).name()), format (byte_pair (3,6))
{

}

void nsInformation::InformationHolder::operator << (const nsInformation::FilePath & fp) noexcept
{
    dirs.push_back (fp);
}


