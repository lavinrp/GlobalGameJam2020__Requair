#include <Requair/Core/GameObjects/Arm.h>


REQ::Arm::Arm(float x, float y) : SpriteItem(0), hasBeenGrabbed(false)
{
	this->setPosition(x, y);
	this->setTexture(m_texture, true);
}

void REQ::Arm::Interact(REQ::Boss& boss)
{
	if (!hasBeenGrabbed)
	{
		boss.GainArm();
		this->setTextureRect(sf::IntRect(0, 0, 1, 1));
		hasBeenGrabbed = true;
	}
}

bool REQ::Arm::IsCollectible() {
	return !hasBeenGrabbed;
}
