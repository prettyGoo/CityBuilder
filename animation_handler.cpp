#include <SFML/Graphics.hpp>
#include <vector>

#include "animation_handler.hpp"
#include "animation_handler.hpp"


void AnimationHandler::update(const float dt)
{
    if (currentAnimation > this->animations.size() || currentAnimation < 0)
    {
        return;
    }

    float duration = this->animations[currentAnimation].duration;

    if (int((t + dt) / duration) > int(t / duration))
    {
        int frame = int((t+dt) / duration);
        frame %= this->animations[currentAnimation].getLength();

        sf::IntRect rect = this->frameSize;
        rect.left = rect.width * frame;
        rect.top = rect.height * this->currentAnimation;
        this->bounds = rect;
    }

    this->t += dt;
    if (this->t > duration * this->animations[currentAnimation].getLength())
    {
        this->t = 0.0f;
    }

    return;
}

void AnimationHandler::addAnimation(Animation &animation)
{
    this->animations.push_back(animation);

    return;
}

void AnimationHandler::changeAnimation(int animationNumber)
{
    if (animationNumber > this->animations.size() || animationNumber < 0 || this->currentAnimation == animationNumber)
    {
        return;
    }

    this->currentAnimation = animationNumber;

    sf::IntRect rect = this->frameSize;
    rect.top = rect.height * animationNumber;
    this->bounds = rect;
    this->t = 0.0f;

    return;
}

