#include <Requair/Core/GameObjects/Floor.h>

#include <Requair/Core/GameObjects/Item.h>


using namespace REQ;

Floor::Floor(float x, float y) : SpriteItem(1000)
{
	this->setPosition(x, y);
	this->setTexture(m_texture, true);
}

void Floor::Interact()
{
	
}
