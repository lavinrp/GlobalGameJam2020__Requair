#include <Requair/Core/GameObjects/Pot.h>
#include <GameBackbone/Core/AnimatedSprite.h>

using namespace REQ;

Pot::Pot(float x, float y) : Item(100), GB::AnimatedSprite(),
	m_broken(false)
{
}

void Pot::update(sf::Int64 elapsedTime)
{
	GB:AnimatedSprite::update(elapsedTime);
	PhysicalObject::update(elapsedTime);
}

void Pot::Translate(sf::Vector2f offset)
{
	move(offset);
}

sf::FloatRect Pot::GetObjectBounds() const
{
	return getGlobalBounds();
}

sf::Vector2f Pot::GetObjectPosition() const
{
	return getPosition();
}

void Pot::Interact()
{
	m_broken = !m_broken;
}
