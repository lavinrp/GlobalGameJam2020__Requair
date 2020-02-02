#include <Requair/Core/Actions/ForkAction.h>

using namespace REQ;

ForkAction::ForkAction(std::unique_ptr<Action> nextAction, std::unique_ptr<Action>otherNextAction)
    : m_firstNextAction(std::move(nextAction)), m_otherNextAction(std::move(otherNextAction)) {}

bool ForkAction::Perform(sf::Int64 elapsedTime)
{
    if (m_isFinished)
    {
        return true;
    }
    return false;
}

void ForkAction::update(sf::Int64 elapsedTime)
{
    if (Perform(elapsedTime))
    {
        m_firstNextAction->Perform(elapsedTime);
        m_otherNextAction->Perform(elapsedTime);
    }
}

// Dummy implementation. Should not use.
Action& ForkAction::Then(std::unique_ptr<Action> nextAction)
{
    return *(nextAction.get());
};
