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
	spriteSheet.loadFromFile(R"(Textures/Hero Boi/hero boi walk.png)");

	GB::UniformAnimationSet::Ptr uniformAnimationSet = std::make_shared<GB::UniformAnimationSet>(sf::Vector2i(GridSize, GridSize));
	// Add an animation to the UniformAnimationSet
	uniformAnimationSet->addAnimation({
		//{0, 0},		// Top left of the texture
		{1, 0},		// Top middle of the texture
		{2, 0},		// Top right of the texture
		});

	// Create an AnimatedSprite to display the UniformAnimation
	m_hero.setTexture(spriteSheet);
	m_hero.setAnimations(uniformAnimationSet);
	m_pot.setTexture(spriteSheet);
	m_pot.setAnimations(uniformAnimationSet);

	m_hero.setPosition(10 * 128, 3 * 128);
	m_pot.setPosition(10 * 128, 3 * 128);

	// Tell the AnimatedSprite to update every one second
	m_hero.setAnimationDelay(sf::seconds(0.3));
	// Tell the AnimatedSprite to begin running its second animation
	// The animation will reverse directions every time it reaches the beginning or end
	m_hero.runAnimation(0, GB::ANIMATION_END_TYPE::ANIMATION_LOOP);
	m_pot.runAnimation(0, GB::ANIMATION_END_TYPE::ANIMATION_LOOP);

	// Tell the region to draw the AnimatedSprite
	addDrawable(1, &m_hero);
	addDrawable(1, &m_pot);
	

	m_action = std::make_unique<MoveAction>(m_hero, sf::Vector2f{ 7*128, 3 * 128 });
	m_action->Then(std::make_unique<MoveAction>(m_hero, sf::Vector2f{ 10 * 128, 3 * 128 }))
		.Then(std::make_unique<ForkAction>(
			std::make_unique<MoveAction>(m_hero, sf::Vector2f{ 10 * 128, 5 * 128 }),
			std::make_unique<MoveAction>(m_pot, sf::Vector2f{ 10 * 128, 1 * 128 })
		));


	/*MoveAction banana{ m_hero, sf::Vector2f{ 0.0f, 0.0f }, sf::Vector2f{ 10.0f, 10.0f } };
	banana.Then(MoveAction{ GB::AnimatedSprite{}, sf::Vector2f{ 10.0f, 10.0f } })
		.Then(AnimationAction{ GB::AnimatedSprite{} });*/

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