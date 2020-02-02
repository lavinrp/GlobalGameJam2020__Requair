#include <Requair/Core/GameObjects/Leg.h>

REQ::Leg::Leg(float x, float y) : SpriteItem(0)
{
	this->setPosition(x, y);
	this->setTexture(m_texture, true);
}

void REQ::Leg::Interact()
{

}

bool REQ::Leg::IsCollectible() {
	return true;
}
