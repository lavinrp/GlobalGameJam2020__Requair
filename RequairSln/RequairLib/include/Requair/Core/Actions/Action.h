#pragma once

#include <Requair/Utils/DllUtils.h>

#include <GameBackbone/Core/Updatable.h>


namespace REQ
{
    class libRequair Action : public GB::Updatable
    {
    public:
        Action::Action();

        virtual bool Perform(sf::Int64 elapsedTime);
        virtual Action& Then(Action& nextAction);

        void update(sf::Int64 elapsedTime) override;

    protected:
        bool m_isFinished;

    private:
        Action* m_nextAction;
    };
}