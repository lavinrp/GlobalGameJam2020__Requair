#include <Requair/Core/GameObjects/Door.h>

#include <Requair/Core/GameObjects/Item.h>
#include <Requair/Core/GameObjects/AnimatedItem.h>


using namespace REQ;

Door::Door(float x, float y) : AnimatedItem(1000),
m_broken(false)
{

	this->setPosition(x, y);
	this->setTexture(m_texture, true);
	this->setAnimations(m_animations);
	this->setCurrentAnimation(0);
	this->setAnimating(false);
}

void Door::Interact()
{

	m_broken = !m_broken;
	if (m_broken)
	{
		setCurrentFrame(1);
	}
	else
	{
		setCurrentFrame(0);
	}
}