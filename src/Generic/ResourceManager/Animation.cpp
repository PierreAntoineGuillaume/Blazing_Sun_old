#include "Animation.h"

Animation::Animation() : texture(NULL)
{ }

void Animation::addFrame(sf::IntRect rect)
{
    frames.push_back(rect);
}

void Animation::removeFrame(std::size_t frame)
{
    frames.erase(frames.begin() + frame);
}

sf::Sprite Animation::getSprite(std::size_t frame)
{
    sprite.setTextureRect(frames.at(frame));
    return sprite;
}

void Animation::setSpriteSheet(const sf::Texture &text)
{
    texture = &text;
    sprite.setTexture(*texture);
}

const sf::Texture *Animation::getSpriteSheet() const
{
    return texture;
}

std::size_t Animation::getSize() const
{
    return frames.size();
}
