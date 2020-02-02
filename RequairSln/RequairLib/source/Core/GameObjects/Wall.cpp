#include <Requair/Core/GameObjects/Wall.h>

#include <Requair/Core/GameObjects/Item.h>


using namespace REQ;

Wall::Wall(float x, float y) : SpriteItem(1000)
{
	this->setPosition(x, y);
	this->setTexture(m_texture, true);
}

void Wall::Interact()
{
	
}
