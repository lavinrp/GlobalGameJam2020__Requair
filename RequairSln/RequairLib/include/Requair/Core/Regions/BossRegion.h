#pragma once

#include <Requair/Utils/DllUtils.h>

#include <Requair/Core/Regions/RuntimeRegion.h>
#include <SFML/Graphics/RectangleShape.hpp>

#include <Requair/Core/Boss/Boss.h>

namespace REQ
{
    class libRequair BossRegion : public RuntimeRegion
    {
    public:
        BossRegion(std::string jsonFile);
        BossRegion() = delete;
		void HandleEvent(sf::Event& event) override;
		void update(sf::Int64 elapsedTime) override;

    private:
		//sf::RectangleShape boss;
		REQ::Boss boss;
		sf::Vector2f bossOrigin = sf::Vector2f(200, 200);
        float maxInteractionDistance = 100.0;
    };
}