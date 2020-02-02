#pragma once
#include <Requair/Utils/DllUtils.h>
#include <Requair/Core/GameObjects/Item.h>

#include <GameBackbone/Core/AnimatedSprite.h>

#include <SFML/Graphics/Texture.hpp>

namespace REQ
{
	class libRequair AnimatedItem : public Item, public GB::AnimatedSprite
	{
	public:
		AnimatedItem(unsigned int weight);

		void Translate(sf::Vector2f offset) override;
		sf::FloatRect GetObjectBounds() const override;
		sf::Vector2f GetObjectPosition() const override;
		void update(sf::Int64 elapsedTime) override;

	private:
	};
}