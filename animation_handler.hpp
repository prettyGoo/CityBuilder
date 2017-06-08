#ifndef ANIMATION_HANDLER_HPP
#define ANIMATION_HANDLER_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
    public:

    int startFrame;
    int endFrame;
    float duration;

    int getLength()
    {
        return endFrame - startFrame + 1;
    }

    Animation(int startFrame, int endFrame, float duration)
    {
        this->startFrame = startFrame;
        this->endFrame = endFrame;
        this->duration = duration;
    }
};


class AnimationHandler
{
    private:
    std::vector<Animation> animations;

    float t;
    int currentAnimation;

    public:

    void addAnimation(Animation& animation);
    void update(const float dt);
    void changeAnimation(int animationNumber);

    sf::IntRect bounds;
    sf::IntRect frameSize;

    AnimationHandler()
    {
        this->t = 0.0f;
        this->currentAnimation = -1;
    }

    AnimationHandler(sf::IntRect& frameSize)
    {
        this->frameSize = frameSize;
        this->t = 0.0f;
        this->currentAnimation = -1;
    }
};

#endif /* ANIMATION_HANDLER_HPP */
