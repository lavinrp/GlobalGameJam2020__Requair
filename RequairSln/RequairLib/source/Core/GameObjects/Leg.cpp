#include <Requair/Core/GameObjects/Leg.h>

#include <SFML/Graphics/Sprite.hpp>


REQ::Leg::Leg(float x, float y) : SpriteItem(0), hasBeenGrabbed(false)
{
	this->setPosition(x, y);
	this->setTexture(m_texture, true);
}

void REQ::Leg::Interact(REQ::Boss& boss)
{
	if (!hasBeenGrabbed)
	{
		boss.GainLegs();
		this->setTextureRect(sf::IntRect(0, 0, 1, 1));
		hasBeenGrabbed = true;
	}
}

bool REQ::Leg::IsCollectible() {
	return !hasBeenGrabbed;
}
