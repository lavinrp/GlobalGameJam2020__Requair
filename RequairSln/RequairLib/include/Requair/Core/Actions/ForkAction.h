#pragma once

#include <Requair/Utils/DllUtils.h>

#include <Requair/Core/Actions/Action.h>


namespace REQ
{
    class libRequair ForkAction : public Action
    {
    public:
        ForkAction::ForkAction(std::unique_ptr<Action> nextAction, std::unique_ptr<Action> otherNextAction);

        bool Perform(sf::Int64 elapsedTime) override;
        void update(sf::Int64 elapsedTime) override;

    protected:
        std::unique_ptr<Action> m_firstNextAction;
        std::unique_ptr<Action> m_otherNextAction;

    private:
        Action& Then(std::unique_ptr<Action> nextAction) override;
    };
}