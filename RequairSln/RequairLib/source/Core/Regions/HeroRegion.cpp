#include <Requair/Core/Regions/HeroRegion.h>


#include <Requair/Core/Actions/AnimationAction.h>
#include <Requair/Core/Actions/ForkAction.h>
#include <Requair/Core/Actions/MoveAction.h>

#include <GameBackbone/Core/UniformAnimationSet.h>

#include <SFML/Graphics/RenderWindow.hpp>

#include <memory>
#include <iostream>

const int GridSize = 128;

using namespace REQ;

HeroRegion::HeroRegion(const std::string& jsonFile, sf::RenderWindow& window) : TemplateRegion(), m_window(window)
{
	m_heroSpriteSheet.loadFromFile(R"(Textures/Hero Boi/HeroFull.png)");
	m_bossSpriteSheet.loadFromFile(R"(Textures/Boss Man/BossFull.png)");

	GB::UniformAnimationSet::Ptr heroAnimationSet = std::make_shared<GB::UniformAnimationSet>(sf::Vector2i(GridSize, GridSize));
	// Add an animation to the UniformAnimationSet

	heroAnimationSet->addAnimation({
		{0, 0},
	});

	heroAnimationSet->addAnimation({
		{1, 0},
		{2, 0},
		});

	heroAnimationSet->addAnimation({
		{0, 1},		// Top left of the texture
		{1, 1},		// Top middle of the texture
		});

	// Create an AnimatedSprite to display the UniformAnimation
	m_hero.setTexture(m_heroSpriteSheet);
	m_hero.setAnimations(heroAnimationSet);
	m_hero.setPosition(10 * GridSize, 3 * GridSize);
	m_hero.setAnimationDelay(sf::seconds(0.3));


	GB::UniformAnimationSet::Ptr bossAnimationSet = std::make_shared<GB::UniformAnimationSet>(sf::Vector2i(GridSize, GridSize));
	// Add an animation to the UniformAnimationSet

	bossAnimationSet->addAnimation({ // Idle
		{0, 0},
		});

	bossAnimationSet->addAnimation({ // Walk towards camera
		{1, 0},
		{2, 0},
		});

	bossAnimationSet->addAnimation({ // Idle Away form camera
		{0, 1},
			});
	bossAnimationSet->addAnimation({ // Walk away from camera
		{1, 1},
		{2, 1},
		});

	bossAnimationSet->addAnimation({ // Idle no arm
		{0, 2},
		});

	bossAnimationSet->addAnimation({ // Walk without arm 
		{1, 2},
		{2, 2},
		});

	bossAnimationSet->addAnimation({ // Idle no legs
		{0, 2},
			});


	bossAnimationSet->addAnimation({ // Walk without legs 
		{1, 3},
		{2, 3},
		});


	m_boss.setTexture(m_bossSpriteSheet);
	m_boss.setAnimations(bossAnimationSet);
	m_boss.setPosition(1 * GridSize, 2 * GridSize);
	m_boss.setAnimationDelay(sf::seconds(0.3));

	//// Tell the region to draw the AnimatedSprite
	addDrawable(1, &m_hero);
	addDrawable(1, &m_boss);

	//auto MoveSetupFun = [&](GB::AnimatedSprite& animSprite) -> void
	//{
	//	animSprite.setTexture(spriteSheet);
	//	animSprite.runAnimation(0, GB::ANIMATION_END_TYPE::ANIMATION_LOOP);
	//};
	//auto SwipeSetupFun = [&](GB::AnimatedSprite& animSprite) -> void
	//{
	//	animSprite.setTexture(spriteSheet2);
	//	animSprite.runAnimation(1, GB::ANIMATION_END_TYPE::ANIMATION_STOP);
	//};

	//std::unique_ptr<MoveAction> moveThenSlash = std::make_unique<MoveAction>(m_hero, sf::Vector2f{ 10 * 128, 5 * 128 }, MoveSetupFun);
	//moveThenSlash->Then(std::make_unique<AnimationAction>(m_hero, SwipeSetupFun, true));

	//m_action = std::make_unique<MoveAction>(m_hero, sf::Vector2f{ 7*128, 3 * 128 }, MoveSetupFun);
	//m_action->Then(std::make_unique<MoveAction>(m_hero, sf::Vector2f{ 10 * 128, 3 * 128 }, MoveSetupFun))
	//	.Then(std::make_unique<ForkAction>(
	//		std::move(moveThenSlash),
	//		std::make_unique<MoveAction>(m_pot, sf::Vector2f{ 10 * 128, 1 * 128 }, MoveSetupFun)
	//	));


	///*MoveAction banana{ m_hero, sf::Vector2f{ 0.0f, 0.0f }, sf::Vector2f{ 10.0f, 10.0f } };
	//banana.Then(MoveAction{ GB::AnimatedSprite{}, sf::Vector2f{ 10.0f, 10.0f } })
	//	.Then(AnimationAction{ GB::AnimatedSprite{} });*/

}


void HeroRegion::update(sf::Int64 elapsedTime)
{
	m_action->update(elapsedTime);

	sf::View view = m_window.getView();
	view.setCenter(m_hero.getPosition());
	m_window.setView(view);
}

void HeroRegion::HandleEvent(sf::Event& event) {

}