#pragma once

#include <Requair/Utils/DllUtils.h>

#include <SFML/Window/Event.hpp>

#include <GameBackbone/Core/GameRegion.h>
#include <Requair/Core/GameObjects/Pot.h>


#include <SFML/Audio/Music.hpp>


namespace REQ
{
    class libRequair TemplateRegion : public GB::GameRegion
    {
    public:
		virtual void HandleEvent(sf::Event& even) = 0;

        std::unique_ptr <sf::Music> m_music;
    };
}