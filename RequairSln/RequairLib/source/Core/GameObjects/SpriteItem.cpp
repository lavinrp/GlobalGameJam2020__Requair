#include <Requair/Core/GameObjects/SpriteItem.h>

#include <SFML/Graphics/Sprite.hpp>


sf::FloatRect REQ::SpriteItem::GetObjectBounds() const
{
	return sf::Sprite::getGlobalBounds();
}

sf::Vector2f REQ::SpriteItem::GetObjectPosition() const
{
	return sf::Sprite::getPosition();
}

void REQ::SpriteItem::Translate(sf::Vector2f velocity)
{
	sf::Sprite::move(velocity);
}