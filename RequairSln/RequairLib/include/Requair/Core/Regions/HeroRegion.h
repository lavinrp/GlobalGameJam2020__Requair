#pragma once

#include <Requair/Utils/DllUtils.h>

#include <Requair/Core/Actions/MoveAction.h>
//#include <Requair/Core/Actions/AnimationAction.h>
#include <Requair/Core/Regions/TemplateRegion.h>

#include <GameBackbone/Core/AnimatedSprite.h>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

//#include <utility>
//#include <vector>
#include <memory>


namespace REQ
{
    class libRequair HeroRegion : public TemplateRegion
    {
    public:
        HeroRegion(const std::string& jsonFile, sf::RenderWindow& window);
        HeroRegion() = delete;
		void HandleEvent(sf::Event& even) override;

        void update(sf::Int64 elapsedTime) override;

    private:
        using ItemPointerVec = std::vector<std::unique_ptr<Item>>;
        using PhysicalObjectPtrVec = std::vector<std::unique_ptr<PhysicalObject>>;

        ItemPointerVec m_item_list;
        PhysicalObjectPtrVec m_physical_object_list;
        std::pair< ItemPointerVec, PhysicalObjectPtrVec > ProcessJson(const std::string& jsonFile);


        // Hero
        GB::AnimatedSprite m_hero;
        GB::AnimatedSprite m_boss;

        GB::AnimatedSprite m_arm;
        GB::AnimatedSprite m_leg;
        std::unique_ptr<Action> m_action;

        // ActionSet = Start Point, End Point, Action, Other Sprite/Object that moves?
        /*using ActionSet = std::tuple<sf::Vector2f, sf::Vector2f, int>;
        std::vector<ActionSet> m_coordinates;*/


        sf::RenderWindow& m_window;
        sf::Texture m_heroSpriteSheet;
        sf::Texture m_bossSpriteSheet;
        sf::Texture m_armSpriteSheet;
        sf::Texture m_legSpriteSheet;
    };
}