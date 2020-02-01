#pragma once

#include <Requair/Utils/DllUtils.h>

#include <Requair/Core/Regions/RuntimeRegion.h>
#include <SFML/Graphics/RectangleShape.hpp>


namespace REQ
{
    class libRequair BossRegion : public RuntimeRegion
    {
    public:
        BossRegion(std::string jsonFile);
        BossRegion() = delete;
		void HandleEvent(sf::Event& even) override;

    private:
		sf::RectangleShape boss;
		sf::Vector2f bossOrigin = sf::Vector2f(200, 200);
		sf::Vector2f bossPos;
		sf::Vector2f bossSpeed = sf::Vector2f(5, 5);
		sf::Vector2f bossSize = sf::Vector2f(25, 50);
        // Player (boss)

    };
}