#pragma once

#include <Requair/Utils/DllUtils.h>
#include <Requair/Core/GameObjects/Item.h>
#include <Requair/Core/GameObjects/AnimatedItem.h>
#include <SFML/Graphics/Texture.hpp>

namespace REQ
{
	class libRequair Pot : public AnimatedItem
	{
	public:
		Pot(float x, float y);

		void Interact() override;

	private:
		bool m_broken;
		sf::Texture m_texture = [] () {
			sf::Texture tex{};
			tex.loadFromFile("Textures/Pot.png");
			return tex;
		}();
		static inline GB::AnimationSet::Ptr m_animations = []() -> GB::AnimationSet::Ptr {
			GB::AnimationSet::Ptr animSet = std::make_shared<GB::AnimationSet>();
			animSet->addAnimation({ {0, 0, 400, 400} });
			animSet->addAnimation({ {400, 0, 400, 400} });
			return animSet;
		} ();
	};
}