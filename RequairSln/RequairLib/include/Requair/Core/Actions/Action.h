#pragma once

#include <Requair/Utils/DllUtils.h>

#include <GameBackbone/Core/Updatable.h>

#include <memory>

namespace REQ
{
    class libRequair Action : public GB::Updatable
    {
    public:
        Action::Action();

        virtual bool Perform(sf::Int64 elapsedTime);
        virtual Action& Then(std::unique_ptr<Action> nextAction);

        void update(sf::Int64 elapsedTime) override;

    protected:
        bool m_isFinished;

    private:
        std::unique_ptr<Action> m_nextAction;
    };
}