#include <iostream>
#include "Animator.h"

Animator::Animator(sf::Time frameTime, bool paused, bool looped) :
        texture(NULL), animation(NULL), frametime(frameTime), currentFrame(0), paused(paused), looped(looped)
{ }

/** Updates the current frame id */
void Animator::update(sf::Time deltaTime)
{
    // if not paused and we have a valid animation
    if (!paused && animation)
    {
        // add delta time
        currentTime += deltaTime;

        // if current time is bigger then the frame time advance one frame
        if (currentTime >= frametime)
        {
            // reset the time, but keeps the rest in memory, to avoid lags
            currentTime = sf::microseconds(currentTime.asMicroseconds() % frametime.asMicroseconds());

            // get next Frame index
            if (currentFrame + 1 < animation->getSize())
                currentFrame++;
            else
            {
                // animation has ended
                currentFrame = 0; // reset to start
                //if the animation is not looped, we stops there
                if (!looped)
                {
                    paused = true;
                }
            }
        }
    }
}

void Animator::render(sf::RenderTarget &target, float x, float y)
{
    if (animation && texture)
    {
        sf::Sprite sprite = animation->getSprite(currentFrame);
        sprite.setPosition(x, y);
        target.draw(sprite);
    }
}

void Animator::setAnimation(Animation &anim)
{
    this->animation = &anim;
    this->texture = this->animation->getSpriteSheet();
}

void Animator::play()
{
    this->paused = false;
}

void Animator::pause()
{
    this->paused = true;
}

void Animator::stop()
{
    this->paused = true;
    this->currentFrame = 0;
}


// GETTERS

bool Animator::isLooped() const
{
    return this->looped;
}

bool Animator::isPlaying() const
{
    return !paused;
}

sf::Time Animator::getFrameTime() const
{
    return frametime;
}

const Animation *Animator::getAnimation() const
{
    return animation;
}


// SETTERS


void Animator::setLooped(bool looped)
{
    this->looped = looped;
}

void Animator::setFrameTime(sf::Time time)
{
    this->frametime = time;
}