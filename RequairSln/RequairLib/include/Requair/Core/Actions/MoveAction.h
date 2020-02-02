#pragma once

#include <Requair/Utils/DllUtils.h>

#include <Requair/Core/Actions/AnimationAction.h>

#include <SFML/System/Vector2.hpp>


namespace REQ
{
    class libRequair MoveAction : public AnimationAction
    {
    public:
        MoveAction() = delete;
        MoveAction(GB::AnimatedSprite& thingToMove, sf::Vector2f endPoint, std::function<void(GB::AnimatedSprite&)> setup);

        bool Perform(sf::Int64 elapsedTime) override;

    private:
        sf::Vector2f m_endPoint;
    };
}