#include <Requair/Core/GameObjects/Arm.h>


REQ::Arm::Arm(float x, float y) : SpriteItem(0)
{
	this->setPosition(x, y);
	this->setTexture(m_texture, true);
}

void REQ::Arm::Interact()
{

}
