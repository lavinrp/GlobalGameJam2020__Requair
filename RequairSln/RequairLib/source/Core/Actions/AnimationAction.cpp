#include <Requair/Core/Actions/AnimationAction.h>

using namespace REQ;

AnimationAction::AnimationAction(GB::AnimatedSprite& thingToAnimate) : m_thingToAnimate(thingToAnimate) {}

void AnimationAction::update(sf::Int64 elapsedTime)
{
    // TODO: Animate the thing?
}