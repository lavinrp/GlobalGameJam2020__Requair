#pragma once

#include <Requair/Utils/DllUtils.h>
#include <Requair/Core/GameObjects/Item.h>
#include <SFML/Graphics/Sprite.hpp>

namespace REQ
{
	class libRequair Key : public Item, public sf::Sprite
	{
	public:

		void Interact() override;

		sf::FloatRect GetObjectBounds() const override;

		sf::Vector2f GetObjectPosition() const override;

		void Translate(sf::Vector2f velocity);
		
	};

}