#include <Requair/Core/Regions/HeroRegion.h>


#include <Requair/Core/Actions/AnimationAction.h>

#include <GameBackbone/Core/UniformAnimationSet.h>

#include <memory>
#include <iostream>

const int GridSize = 128;

using namespace REQ;

HeroRegion::HeroRegion(const std::string& jsonFile) : TemplateRegion()
{
	spriteSheet.loadFromFile(R"(Textures/boss_man_walk.png)");

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

	// Move the AnimatedSprite
	m_hero.move(150.0f, 0.0f);
	// Tell the AnimatedSprite to update every one second
	m_hero.setAnimationDelay(sf::seconds(0.3));
	// Tell the AnimatedSprite to begin running its second animation
	// The animation will reverse directions every time it reaches the beginning or end
	m_hero.runAnimation(0, GB::ANIMATION_END_TYPE::ANIMATION_LOOP);


	// Tell the region to draw the AnimatedSprite
	addDrawable(1, &m_hero);
	

	m_action = std::make_unique<MoveAction>(m_hero, sf::Vector2f{ 150.0f, 550.0f });

	/*MoveAction banana{ m_hero, sf::Vector2f{ 0.0f, 0.0f }, sf::Vector2f{ 10.0f, 10.0f } };
	banana.Then(MoveAction{ GB::AnimatedSprite{}, sf::Vector2f{ 10.0f, 10.0f } })
		.Then(AnimationAction{ GB::AnimatedSprite{} });*/

}


void HeroRegion::update(sf::Int64 elapsedTime)
{
	m_action->update(elapsedTime);
	//std::cout << m_hero.getPosition().x << " " << m_hero.getPosition().y << "\n";
	std::cout << getDrawableCount()<< "\n";
}