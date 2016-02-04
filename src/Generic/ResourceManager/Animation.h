#pragma once

#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Animation
{
private:
    std::vector<sf::IntRect> frames;
    const sf::Texture *texture;
    sf::Sprite sprite;


public:
    Animation();

    /**
     * Add a frame to the animation loop.
     */
    void addFrame(sf::IntRect rect);

    /**
     * removes a specific frame, if frame = 0, removes the first element, etc...
     */
    void removeFrame(std::size_t frame);

    /** Gets the sprite corresponding to the frame, to draw on the screen */
    sf::Sprite getSprite(std::size_t frame);

    /**
     * Sets the unique spriteSheet for this animation,
     * can be changed on runtime
     */
    void setSpriteSheet(const sf::Texture &texture);

    const sf::Texture *getSpriteSheet() const;

    std::size_t getSize() const;
};