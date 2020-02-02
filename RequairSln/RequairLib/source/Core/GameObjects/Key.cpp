#include <Requair/Core/GameObjects/Key.h>

REQ::Key::Key(float x, float y) : SpriteItem(0)
{
	this->setPosition(x, y);
	this->setTexture(m_texture, true);
}


void REQ::Key::Interact()
{

}


bool REQ::Key::IsCollectible() {
	return true;
}