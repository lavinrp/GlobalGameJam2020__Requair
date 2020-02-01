#include <Requair/Core/Regions/BossRegion.h>
#include <SFML/Graphics/RectangleShape.hpp>
//include <SFML/Graphics/Color.hpp>

using namespace REQ;

BossRegion::BossRegion(std::string jsonFile) : RuntimeRegion(jsonFile)
{

	//bossOrigin.x = 50;
	//bossOrigin.y = 50;

	bossPos.x = bossOrigin.x;
	bossPos.y = bossOrigin.y;

	boss.setPosition(bossPos);
	boss.setSize(bossSize);

	addDrawable(5, &boss);
}

void BossRegion::HandleEvent(sf::Event& event) {


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

		boss.setPosition(bossPos);

		/*if (event.key.code == 71 || event.key.code == 72 ||
			event.key.code == 73 || event.key.code == 74) {

			std::cout << event.key.code;
			std::cout << " ";
		}
		else {

			std::cout << ".";
		}*/
	}
}