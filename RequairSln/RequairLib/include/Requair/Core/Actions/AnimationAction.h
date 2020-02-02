#pragma once

#include <Requair/Utils/DllUtils.h>

#include <Requair/Core/Actions/Action.h>

#include <GameBackbone/Core/AnimatedSprite.h>

namespace REQ
{
    class libRequair AnimationAction : public Action
    {
    public:
        AnimationAction() = delete;
        AnimationAction(GB::AnimatedSprite& thingToAnimate, bool shouldStop = false);

        bool Perform(sf::Int64 elapsedTime) override;

    protected:
        GB::AnimatedSprite& m_thingToAnimate;
        bool m_shouldStop;
    };
}