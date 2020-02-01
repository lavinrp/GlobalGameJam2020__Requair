#include <Requair/Core/GameObjects/AnimatedItem.h>

using namespace REQ;

AnimatedItem::AnimatedItem(unsigned int weight) : Item(weight), AnimatedSprite()
{
}

void AnimatedItem::Translate(sf::Vector2f offset)
{
	move(offset);
}

sf::FloatRect AnimatedItem::GetObjectBounds() const
{
	return getGlobalBounds();
}

sf::Vector2f AnimatedItem::GetObjectPosition() const
{
	return getPosition();
}

void AnimatedItem::update(sf::Int64 elapsedTime)
{
	GB::AnimatedSprite::update(elapsedTime);
	PhysicalObject::update(elapsedTime);
}