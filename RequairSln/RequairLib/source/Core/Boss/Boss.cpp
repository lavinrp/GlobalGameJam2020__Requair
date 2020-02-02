#include <Requair/Core/Boss/Boss.h>

#include <SFML/Window/Event.hpp>

#include <GameBackbone/Core/AnimatedSprite.h>
#include <GameBackbone/Core/AnimationSet.h>
#include <GameBackbone/Core/GameRegion.h>
#include <GameBackbone/Core/UniformAnimationSet.h>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <memory>


using namespace REQ;

Boss::Boss() {

	std::cout << spriteSheet.loadFromFile(R"(Textures/boss_man_walk.png)");

	int frameDimX = spriteSheet.getSize().x / 3;
	int frameDimY = spriteSheet.getSize().y;

	GB::UniformAnimationSet::Ptr uniformAnimationSet = std::make_shared<GB::UniformAnimationSet>(sf::Vector2i(frameDimX, frameDimY));
	uniformAnimationSet->addAnimation({
		{0, 0},	
		{1, 0},	
		{2, 0},
		});
	
	setTexture(spriteSheet);
	setAnimations(uniformAnimationSet);

	setAnimationDelay(sf::seconds(0.3));

	bossPos = getPosition();
	//runAnimation(0, GB::ANIMATION_END_TYPE::ANIMATION_LOOP);
}

void Boss::MovementControls(sf::Event& event) {

	if (sf::Event::KeyPressed) {

		if (event.key.code == 71 || event.key.code == 97 || event.key.code == 65) {
			bossPos.x -= bossSpeed.x;
		}
		else if (event.key.code == 72 || event.key.code == 100 || event.key.code == 68) {
			bossPos.x += bossSpeed.x;
		}

		if (event.key.code == 73 || event.key.code == 119 || event.key.code == 87) {
			bossPos.y -= bossSpeed.y;
		}
		else if (event.key.code == 74 || event.key.code == 115 || event.key.code == 83) {
			bossPos.y += bossSpeed.y;
		}
	}
}


void Boss::update(sf::Int64 elapsedTime) {

	AnimatedSprite::update(elapsedTime);

	setPosition(bossPos);
}
