#pragma once

#include <Requair/Utils/DllUtils.h>

#include <SFML/Window/Event.hpp>

#include <GameBackbone/Core/GameRegion.h>


namespace REQ
{
    class libRequair TemplateRegion : public GB::GameRegion
    {
    public:
        using GB::GameRegion::GameRegion;
		virtual void HandleEvent(sf::Event& even) = 0;
    };
}