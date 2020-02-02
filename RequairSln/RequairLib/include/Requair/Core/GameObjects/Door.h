#pragma once

#include <Requair/Utils/DllUtils.h>

#include <Requair/Core/GameObjects/SpriteItem.h>
#include <Requair/Core/GameObjects/AnimatedItem.h>

#include <GameBackbone/Core/UniformAnimationSet.h>
#include <SFML/Graphics/Texture.hpp>

namespace REQ
{
	class libRequair Door : public AnimatedItem
	{
	public:
		Door(float x, float y);

		void Interact() override;

	private:
		bool m_broken;
		sf::Texture m_texture = []() {
			sf::Texture tex{};
			tex.loadFromFile("Textures/Room/Door on Floor.png");
			// tex.loadFromFile("Textures/Wall tile.png");
			return tex;
		}();

		static inline GB::AnimationSet::Ptr m_animations = []() -> GB::AnimationSet::Ptr {
			GB::UniformAnimationSet::Ptr animSet = std::make_shared<GB::UniformAnimationSet>(sf::Vector2i{ 64, 128 });
			animSet->addAnimation({
				{0, 0},
				{1, 0},
				});
			return animSet;
		} ();
	};
}