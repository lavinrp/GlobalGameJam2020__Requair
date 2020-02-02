#pragma once

#include <Requair/Utils/DllUtils.h>

#include <Requair/Core/GameObjects/SpriteItem.h>

#include <SFML/Graphics/Texture.hpp>

namespace REQ
{
	class libRequair Wall : public SpriteItem
	{
	public:
		Wall(float x, float y);

		void Interact() override;

	private:
		sf::Texture m_texture = [] () {
			sf::Texture tex{};
			tex.loadFromFile("Textures/Wall tile.png");
			return tex;
		}();
	};
}