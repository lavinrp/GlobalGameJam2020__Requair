#pragma once

#include <Requair/Utils/DllUtils.h>
#include <Requair/Core/GameObjects/Item.h>

#include <GameBackbone/Core/AnimatedSprite.h>

namespace REQ
{
	class libRequair Pot : public Item, public GB::AnimatedSprite
	{
	public:
		Pot(float x, float y);

	private:
		bool m_broken;
	};
}