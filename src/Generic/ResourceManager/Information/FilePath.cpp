//
// Created by Pierre-Antoine on 09/08/2015.
//

#include "FilePath.h"

nsInformation::MacroFilePath::MacroFilePath (std::string pPath_to_file) :
    path_to_file (pPath_to_file)
{

}

nsInformation::MacroFilePath & nsInformation::MacroFilePath::operator << (const sf::IntRect & box, byte_t index, byte_t duration)
{
    rects.push      (box);
    indexes.push    (index);
    durations.push  (duration);
    return *this;
}

nsInformation::FilePath nsInformation::MacroFilePath::Pop ()
{
    nsInformation::FilePath t;
    t.path_to_file = path_to_file;
    t.index        = (indexes.front ());
    t.duration     = (durations.front());
    t.rect         = (rects.front());

    indexes.pop();
    durations.pop();
    rects.pop();

    return t;
}

bool nsInformation::MacroFilePath::empty () const noexcept
{
    return return indexes.empty();
}
