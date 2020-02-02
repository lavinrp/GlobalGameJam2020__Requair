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

HeroRegion::HeroRegion(const std::string& jsonFile, sf::RenderWindow& window) : TemplateRegion(), m_window(window), m_bossRegion("Levels/3.json", window), m_goToNext(false)
{
	m_music = std::make_unique<sf::Music>();
	if (m_music->openFromFile(R"(Music/fight.wav)"))
	{
		m_music->play();
		m_music->setLoop(true);
	}

	m_heroSpriteSheet.loadFromFile(R"(Textures/Hero Boi/HeroFull.png)");
	m_bossSpriteSheet.loadFromFile(R"(Textures/Boss Man/BossFull.png)");
	m_armSpriteSheet.loadFromFile(R"(Textures/Boss Man/boss man arm.png)");
	m_legSpriteSheet.loadFromFile(R"(Textures/Boss Man/boss man legs.png)");


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
		{0, 3},
		});


	bossAnimationSet->addAnimation({ // Walk without legs 
		{1, 3},
		{2, 3},
		});


	m_boss.setTexture(m_bossSpriteSheet);
	m_boss.setAnimations(bossAnimationSet);
	m_boss.setPosition(1 * GridSize, 2 * GridSize);
	m_boss.setAnimationDelay(sf::seconds(0.3));

	GB::UniformAnimationSet::Ptr armLegAnimationSet = std::make_shared<GB::UniformAnimationSet>(sf::Vector2i(GridSize, GridSize));
	// Add an animation to the UniformAnimationSet

	armLegAnimationSet->addAnimation({
		{0, 0},
		});

	m_arm.setTexture(m_armSpriteSheet);
	m_leg.setTexture(m_legSpriteSheet);
	m_arm.setAnimations(armLegAnimationSet);
	m_leg.setAnimations(armLegAnimationSet);
	m_arm.setPosition(m_boss.getPosition());
	m_leg.setPosition(m_boss.getPosition());
	m_arm.runAnimation(0, GB::ANIMATION_END_TYPE::ANIMATION_STOP);
	m_leg.runAnimation(0, GB::ANIMATION_END_TYPE::ANIMATION_STOP);

	//// Tell the region to draw the AnimatedSprite
	addDrawable(1, &m_hero);
	addDrawable(1, &m_boss);

	auto IdleSetup = [&](GB::AnimatedSprite& animSprite) -> void
	{
		animSprite.runAnimation(0, GB::ANIMATION_END_TYPE::ANIMATION_LOOP);
	};
	auto MoveSetup = [&](GB::AnimatedSprite& animSprite) -> void
	{
		animSprite.runAnimation(1, GB::ANIMATION_END_TYPE::ANIMATION_LOOP);
	};
	auto HeroSwipeSetup = [&](GB::AnimatedSprite& animSprite) -> void
	{
		animSprite.runAnimation(2, GB::ANIMATION_END_TYPE::ANIMATION_STOP);
	};

	auto BossBackIdleSetup = [&](GB::AnimatedSprite& animSprite) -> void
	{
		animSprite.runAnimation(2, GB::ANIMATION_END_TYPE::ANIMATION_LOOP);
	};
	auto BossBackMoveSetup = [&](GB::AnimatedSprite& animSprite) -> void
	{
		animSprite.runAnimation(3, GB::ANIMATION_END_TYPE::ANIMATION_LOOP);
	};
	auto BossArmlessIdleSetup = [&](GB::AnimatedSprite& animSprite) -> void
	{
		animSprite.runAnimation(4, GB::ANIMATION_END_TYPE::ANIMATION_LOOP);
	};
	auto BossArmlessMoveSetup = [&](GB::AnimatedSprite& animSprite) -> void
	{
		animSprite.runAnimation(5, GB::ANIMATION_END_TYPE::ANIMATION_LOOP);
	};
	auto BossLeglessIdleSetup = [&](GB::AnimatedSprite& animSprite) -> void
	{
		animSprite.runAnimation(6, GB::ANIMATION_END_TYPE::ANIMATION_LOOP);
	};
	auto BossLeglessMoveSetup = [&](GB::AnimatedSprite& animSprite) -> void
	{
		animSprite.runAnimation(7, GB::ANIMATION_END_TYPE::ANIMATION_LOOP);
	};
	auto armSetup = [&](GB::AnimatedSprite& animSprite) -> void
	{
		addDrawable(1, &m_arm);
	};
	auto legSetup = [&](GB::AnimatedSprite& animSprite) -> void
	{
		addDrawable(1, &m_leg);
	};

	auto finishHeroRegion = [&, this](GB::AnimatedSprite&) -> void
	{
		m_music.reset();
		m_goToNext = true;
	};

	std::unique_ptr<AnimationAction> cutOffBossLegs = std::make_unique<AnimationAction>(m_boss, BossLeglessIdleSetup);
	std::unique_ptr<MoveAction> armFly = std::make_unique<MoveAction>(m_arm, sf::Vector2f{ 7 * GridSize, 0 * GridSize }, armSetup, 0.0003);
	std::unique_ptr<MoveAction> legFly = std::make_unique<MoveAction>(m_leg, sf::Vector2f{ 6 * GridSize, 5 * GridSize }, legSetup, 0.0003);
	std::unique_ptr<MoveAction> heroRunsAwaySlowly = std::make_unique<MoveAction>(m_hero, sf::Vector2f{ -3 * GridSize, 0 * GridSize }, MoveSetup, 0.00023);
	heroRunsAwaySlowly->Then(std::make_unique<AnimationAction>(m_hero, finishHeroRegion, true));

	std::unique_ptr<MoveAction> moveThenSlash = std::make_unique<MoveAction>(m_hero, sf::Vector2f{ m_boss.getPosition().x + 0.3f*GridSize, m_boss.getPosition().y }, MoveSetup, 0.00015);
	moveThenSlash->Then(std::make_unique<AnimationAction>(m_hero, HeroSwipeSetup, true))
		.Then(std::make_unique<ForkAction>(
			std::make_unique<ForkAction>(std::move(armFly), std::move(legFly)),
			std::make_unique<ForkAction>(std::move(cutOffBossLegs), std::move(heroRunsAwaySlowly))));

	m_action = std::move(moveThenSlash);

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

	if (m_goToNext)
	{
		setNextRegion(m_bossRegion);
	}
}

void HeroRegion::HandleEvent(sf::Event& event) {

}