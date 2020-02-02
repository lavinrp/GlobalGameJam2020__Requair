#pragma once

#include <Requair/Utils/DllUtils.h>

#include <Requair/Core/GameObjects/Item.h>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

namespace REQ
{
	class libRequair SpriteItem : public Item, public sf::Sprite
	{
	public:
		using Item::Item;

		sf::FloatRect GetObjectBounds() const override;

		sf::Vector2f GetObjectPosition() const override;

		void Translate(sf::Vector2f velocity) override;
		
	};

}