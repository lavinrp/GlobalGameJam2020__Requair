#include <Requair/Core/Actions/Action.h>

#include <utility>

using namespace REQ;

Action::Action() : m_isFinished(false) {}

bool Action::Perform(sf::Int64 elapsedTime)
{
    if (m_isFinished)
    {
        return true;
    }
    return false;
}

Action& Action::Then(std::unique_ptr<Action> nextAction)
{
    m_nextAction = std::move(nextAction);
    return *(m_nextAction.get());
};

void Action::update(sf::Int64 elapsedTime)
{
    if (Perform(elapsedTime))
    {
        if (m_nextAction != nullptr)
        {
            m_nextAction->update(elapsedTime);
        }
    }
}