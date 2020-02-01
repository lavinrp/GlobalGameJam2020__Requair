#pragma once

#include <ProjectTemplate/Utils/DllUtils.h>

#include <ProjectTemplate/Core/Regions/RuntimeRegion.h>

#include <GameBackbone/Core/AnimatedSprite.h>

#include <SFML/System/Vector2.hpp>

#include <utility>
#include <vector>


namespace PT
{
    class libProjectTemplate HeroRegion : public RuntimeRegion
    {
    public:
        HeroRegion(std::string jsonFile);
        HeroRegion() = delete;

    private:
        // Hero
        GB::AnimatedSprite m_hero;

        // ActionSet = Start Point, End Point, Action, Other Sprite/Object that moves?
        using ActionSet = std::tuple<sf::Vector2f, sf::Vector2f, int>;
        std::vector<ActionSet> m_coordinates;
    };
}