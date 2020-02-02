#pragma once

#include <Requair/Utils/DllUtils.h>
#include <Requair/Core/GameObjects/Item.h>
#include <Requair/Core/GameObjects/AnimatedItem.h>

#include <GameBackbone/Core/UniformAnimationSet.h>

#include <SFML/Graphics/Texture.hpp>

namespace REQ
{
	class libRequair Pot : public AnimatedItem
	{
	public:
		Pot(float x, float y);

		void Interact(REQ::Boss& boss) override;

	private:
		bool m_broken;
		sf::Texture m_texture = [] () {
			sf::Texture tex{};
			tex.loadFromFile("Textures/3_Stages_of_Pot.png");
			return tex;
		}();
		static inline GB::AnimationSet::Ptr m_animations = []() -> GB::AnimationSet::Ptr {
			GB::UniformAnimationSet::Ptr animSet = std::make_shared<GB::UniformAnimationSet>(sf::Vector2i{128, 128});
			animSet->addAnimation({
				{0, 0},
				{1, 0},
				{2, 0}
				});
			return animSet;
		} ();
	};
}