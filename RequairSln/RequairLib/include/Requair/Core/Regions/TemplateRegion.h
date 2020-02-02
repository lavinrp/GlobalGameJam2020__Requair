#pragma once

#include <Requair/Utils/DllUtils.h>

#include <SFML/Window/Event.hpp>

#include <GameBackbone/Core/GameRegion.h>
#include <Requair/Core/GameObjects/Pot.h>


namespace REQ
{
    class libRequair TemplateRegion : public GB::GameRegion
    {
    public:
		virtual void HandleEvent(sf::Event& even) = 0;
    };
}