#include <Requair/Core/Actions/MoveAction.h>

#include <GameBackbone/Navigation/NavigationTools.h>

using namespace REQ;

MoveAction::MoveAction(GB::AnimatedSprite& thingToMove, sf::Vector2f endPoint) 
    : AnimationAction(thingToMove), m_endPoint(endPoint) {}

bool MoveAction::Perform(sf::Int64 elapsedTime)
{
    if (!AnimationAction::Perform(elapsedTime))
    {
        GB::moveSpriteStepTowardsPoint(m_thingToAnimate, m_endPoint, 0.1f, false);

        if (m_thingToAnimate.getPosition() == m_endPoint)
        {
            m_isFinished = true;
        }
    }
    return true;
}
