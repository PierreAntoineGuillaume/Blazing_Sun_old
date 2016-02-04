#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Vector2.hpp>

#include "Animation.h"

class Animator
{

private:
    const sf::Texture *texture;
    Animation *animation;

    sf::Time frametime;
    sf::Time currentTime;
    std::size_t currentFrame;

    bool paused;
    bool looped;

public:
    Animator(sf::Time frameTime = sf::seconds(0.2f), bool paused = false, bool looped = true);

    /** Updates the animation loop */
    void update(sf::Time deltaTime);

    /** Draws the current animation on the target, at a specific position */
    void render(sf::RenderTarget& target, float x, float y);

    /** Changes the loop (Animation object) */
    void setAnimation(Animation &animation);

    /** starts playing the animation */
    void play();

    /** pauses the animator */
    void pause();

    /** stops the animator, and resets it */
    void stop();


    // GETTERS

    bool isLooped() const;

    bool isPlaying() const;

    sf::Time getFrameTime() const;

    const Animation *getAnimation() const;


    // SETTERS

    void setLooped(bool looped);

    void setFrameTime(sf::Time time);
};