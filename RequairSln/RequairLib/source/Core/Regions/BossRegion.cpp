#include <Requair/Core/Regions/BossRegion.h>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace REQ;

BossRegion::BossRegion(std::string jsonFile) : RuntimeRegion(jsonFile)
{

	addDrawable(5, &boss);
}

void BossRegion::HandleEvent(sf::Event& event) {


	boss.MovementControls(event);
}

void BossRegion::update(sf::Int64 elapsedTime)
{
	RuntimeRegion::update(elapsedTime);
	boss.update(elapsedTime);
}
