#include <Requair/Core/GameObjects/Pot.h>

#include <Requair/Core/GameObjects/AnimatedItem.h>

using namespace REQ;

Pot::Pot(float x, float y) : AnimatedItem(100),
	m_broken(false)
{
	this->setPosition(x, y);
	this->setTexture(m_texture, true);
	this->setAnimations(m_animations);
	this->setCurrentAnimation(0);
	this->setAnimating(false);
}

void Pot::Interact()
{
	m_broken = !m_broken;
	if (m_broken)
	{
		setCurrentAnimation(1);
	}
	else
	{
		setCurrentAnimation(0);
	}
}
