#pragma once
#include <Requair/Utils/DllUtils.h>

#include <Requair/Core/GameObjects/SpriteItem.h>

#include <SFML/Graphics/Texture.hpp>

namespace REQ
{
	class libRequair Floor : public SpriteItem
	{
	public:
		Floor(float x, float y);

		void Interact() override;

	private:
		sf::Texture m_texture = [] () {
			sf::Texture tex{};
			tex.loadFromFile("Textures/Tatami_Mat.png");
			return tex;
		}();
	};
}