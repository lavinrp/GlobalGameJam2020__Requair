#include <Requair/Core/GameObjects/Pot.h>
#include <GameBackbone/Core/AnimatedSprite.h>

using namespace REQ;

Pot::Pot(float x, float y) : Item(100), GB::AnimatedSprite(),
	m_broken(false)
{
}
