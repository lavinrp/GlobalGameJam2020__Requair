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
		void MovementControls(sf::Event& event);
		void update(sf::Int64 elapsedTime) override;
	private:

		sf::Vector2f bossPos;
		sf::Vector2f bossSpeed = sf::Vector2f(5, 5);

		sf::Texture spriteSheet;
	};
}