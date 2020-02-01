#include <Requair/Core/GameObjects/Pot.h>
#include <GameBackbone/Core/AnimatedSprite.h>

using namespace REQ;

Pot::Pot(float x, float y) : AnimatedItem(100),
	m_broken(false)
{
	this->setPosition(x, y);
}

void Pot::Interact()
{
	m_broken = !m_broken;
}
