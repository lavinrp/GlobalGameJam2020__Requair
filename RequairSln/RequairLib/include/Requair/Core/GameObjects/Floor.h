#pragma once
#include <Requair/Utils/DllUtils.h>

#include <Requair/Core/GameObjects/SpriteItem.h>

#include <SFML/Graphics/Texture.hpp>

#include <Requair/Core/Boss/Boss.h>


namespace REQ
{
	class libRequair Floor : public SpriteItem
	{
	public:
		Floor(float x, float y);

		void Interact(Boss& boss) override;

	private:
		sf::Texture m_texture = [] () {
			sf::Texture tex{};
			tex.loadFromFile("Textures/Tatami_Mat.png");
			return tex;
		}();
	};
}