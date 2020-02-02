#pragma once

#include <Requair/Utils/DllUtils.h>
#include <GameBackbone/Core/AnimatedSprite.h>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Event.hpp>



#include <GameBackbone/Core/AnimatedSprite.h>
#include <GameBackbone/Core/AnimationSet.h>
#include <GameBackbone/Core/GameRegion.h>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>


namespace REQ
{
	class libRequair Boss : public GB::AnimatedSprite
	{
	public:
		Boss();
		void update(sf::Int64 elapsedTime) override;
	private:
		float bossSpeed = .0003;
		sf::Texture spriteSheet;
	};
}