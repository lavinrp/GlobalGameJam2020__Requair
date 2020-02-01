#include <Requair/Core/Actions/Action.h>

using namespace REQ;

Action::Action() : m_isFinished(false), m_nextAction(nullptr) {}

bool Action::Perform(sf::Int64 elapsedTime)
{
    if (m_isFinished)
    {
        return true;
    }
    return false;
}

Action& Action::Then(Action& nextAction)
{
    m_nextAction = &nextAction;
    return nextAction;
};

void Action::update(sf::Int64 elapsedTime)
{
    if (Perform(elapsedTime))
    {
        if (m_nextAction != nullptr)
        {
            m_nextAction->Perform(elapsedTime);
        }
    }
}