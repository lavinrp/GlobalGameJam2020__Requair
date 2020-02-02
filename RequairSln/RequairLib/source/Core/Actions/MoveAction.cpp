#include <Requair/Core/Actions/MoveAction.h>

#include <GameBackbone/Navigation/NavigationTools.h>

using namespace REQ;

MoveAction::MoveAction(GB::AnimatedSprite& thingToMove, sf::Vector2f endPoint, std::function<void(GB::AnimatedSprite&)> setup, float pixPerUs)
    : AnimationAction(thingToMove, setup), m_endPoint(endPoint), m_pixPerUs(pixPerUs) {}

bool MoveAction::Perform(sf::Int64 elapsedTime)
{
    if (!AnimationAction::Perform(elapsedTime))
    {
        GB::moveSpriteStepTowardsPoint(m_thingToAnimate, m_endPoint, elapsedTime * m_pixPerUs, false);

        if (m_thingToAnimate.getPosition() == m_endPoint)
        {
            m_isFinished = true;
        }
    }
    return m_isFinished;
}
