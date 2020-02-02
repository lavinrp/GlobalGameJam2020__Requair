#pragma once

#include <Requair/Utils/DllUtils.h>
#include <GameBackbone/Core/AnimatedSprite.h>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Event.hpp>
#include <Requair/Core/GameObjects/PhysicalObject.h>


#include <GameBackbone/Core/AnimatedSprite.h>
#include <GameBackbone/Core/AnimationSet.h>
#include <GameBackbone/Core/GameRegion.h>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>


namespace REQ
{
	class libRequair Boss : public GB::AnimatedSprite, public REQ::PhysicalObject
	{
	public:
		Boss();
		void update(sf::Int64 elapsedTime) override;
		void Translate(sf::Vector2f offset) override;
		sf::FloatRect GetObjectBounds() const override;
		sf::Vector2f GetObjectPosition() const override;

	private:
		float bossSpeed = .0003;
		
		sf::Texture spriteSheet;
	};
}