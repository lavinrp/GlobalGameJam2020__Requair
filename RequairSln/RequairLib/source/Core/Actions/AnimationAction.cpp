#include <Requair/Core/Actions/AnimationAction.h>

#include <GameBackbone/Core/AnimatedSprite.h>

using namespace REQ;

AnimationAction::AnimationAction(GB::AnimatedSprite& thingToAnimate, std::function<void(GB::AnimatedSprite&)> setup, bool shouldStop)
    : m_thingToAnimate(thingToAnimate), m_setup(setup), m_doneSetup(false), m_shouldStop(shouldStop){}

bool AnimationAction::Perform(sf::Int64 elapsedTime)
{
    if (!m_doneSetup)
    {
        m_setup(m_thingToAnimate);
        m_doneSetup = true;
    }

    if (!Action::Perform(elapsedTime))
    {
        // Do animation logic
        m_thingToAnimate.update(elapsedTime);

        // If finished, set isFinished
        if (m_shouldStop && (m_thingToAnimate.getCurrentAnimation() != nullptr && m_thingToAnimate.getCurrentFrame() == m_thingToAnimate.getCurrentAnimation()->size()-1))
        {
            m_isFinished = true;
        }
    }
    return m_isFinished;
}
