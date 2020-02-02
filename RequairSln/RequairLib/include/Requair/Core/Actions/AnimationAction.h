#pragma once

#include <Requair/Utils/DllUtils.h>

#include <Requair/Core/Actions/Action.h>

#include <GameBackbone/Core/AnimatedSprite.h>

#include <functional>

namespace REQ
{

    struct nullsetup
    {
        void operator()(GB::AnimatedSprite&) {}
    };

    class libRequair AnimationAction : public Action
    {
    public:
        AnimationAction() = delete;
        AnimationAction(GB::AnimatedSprite& thingToAnimate, std::function<void(GB::AnimatedSprite&)> setup, bool shouldStop = false);

        bool Perform(sf::Int64 elapsedTime) override;

    protected:
        GB::AnimatedSprite& m_thingToAnimate;
        bool m_shouldStop;
        bool m_doneSetup;
        std::function<void(GB::AnimatedSprite&)> m_setup;
    };
}