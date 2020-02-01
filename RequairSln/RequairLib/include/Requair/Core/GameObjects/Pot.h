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

		void update(sf::Int64 elapsedTime) override;

		void Translate(sf::Vector2f offset) override;

		sf::FloatRect GetObjectBounds() const override;

		sf::Vector2f GetObjectPosition() const override;

		void Interact() override;

	private:
		bool m_broken;
	};
}