#include <Requair/Core/Boss/Boss.h>

#include <SFML/Window/Keyboard.hpp>
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

	m_fullBodyTexture.loadFromFile(R"(Textures/boss_man_walk.png)");
	m_noLegsTexture.loadFromFile(R"(Textures/boss_man_sans_A_L_walk.png)");

	int frameDimX = m_fullBodyTexture.getSize().x / 3;
	int frameDimY = m_fullBodyTexture.getSize().y;

	GB::UniformAnimationSet::Ptr uniformAnimationSet = std::make_shared<GB::UniformAnimationSet>(sf::Vector2i(frameDimX, frameDimY));
	uniformAnimationSet->addAnimation({
		{0, 0}
		});
	uniformAnimationSet->addAnimation({
		{1, 0},	
		{2, 0},
		});
	
	setTexture(m_noLegsTexture);
	setAnimations(uniformAnimationSet);

	setAnimationDelay(sf::seconds(0.3));

	//runAnimation(0, GB::ANIMATION_END_TYPE::ANIMATION_LOOP);
}

void Boss::update(sf::Int64 elapsedTime) {
	AnimatedSprite::update(elapsedTime);

	bool walking = false;

	// movement controls
	auto moveVector = sf::Vector2f();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		moveVector.x -= 1;
		walking = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		moveVector.x += 1;
		walking = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		moveVector.y -= 1;
		walking = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		moveVector.y += 1;
		walking = true;
	}
	auto len = sqrt(moveVector.x * moveVector.x + moveVector.y * moveVector.y);
	if (len > 1)
	{
		moveVector.x /= len;
		moveVector.y /= len;
	}
	setPosition(getPosition() + bossSpeed * elapsedTime * moveVector);
	
	// should walk
	if (walking)
	{
		// currently stationary
		if (!this->isAnimating())
		{
			this->runAnimation(1);
		}
	}
	// should not walk
	else
	{
		// currently walking
		if (this->isAnimating())
		{
			this->setCurrentAnimation(0);
			this->setCurrentFrame(0);
			this->setAnimating(false);
		}
	}

}

void REQ::Boss::GainLegs()
{
	setTexture(m_fullBodyTexture);
	bossSpeed *= 2.0f;
}

void REQ::Boss::LoseLegs()
{
	setTexture(m_noLegsTexture);
	bossSpeed *= 0.5f;
}

void REQ::Boss::GainArm()
{
	setTexture(m_fullBodyTexture);
	//bossSpeed *= 2.0f;
}

void REQ::Boss::LoseArm()
{
	setTexture(m_noLegsTexture);
	//bossSpeed *= 0.5f;
}