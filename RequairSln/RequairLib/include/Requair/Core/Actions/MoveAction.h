#pragma once

#include <Requair/Utils/DllUtils.h>

#include <Requair/Core/Actions/AnimationAction.h>


namespace REQ
{
    class libRequair MoveAction : public AnimationAction
    {
    public:
        MoveAction() = delete;
        MoveAction(GB::AnimatedSprite& thingToMove);

        void update(sf::Int64 elapsedTime) override;

    private:
    };
}