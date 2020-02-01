#include <Requair/Core/Actions/MoveAction.h>

using namespace REQ;

MoveAction::MoveAction(GB::AnimatedSprite& thingToMove) : AnimationAction(thingToMove) {}

void MoveAction::update(sf::Int64 elapsedTime)
{
    // Forward to Animation
    AnimationAction::update(elapsedTime);

    // TODO: Do our Movement
}