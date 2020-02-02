#pragma once

#include <Requair/Utils/DllUtils.h>

#include <SFML/Window/Event.hpp>

#include <Requair/Core/Regions/TemplateRegion.h>


namespace REQ
{
    class libRequair MainMenuRegion : public TemplateRegion
    {
    public:
        MainMenuRegion();
		void HandleEvent(sf::Event& even) override;

    private:

    };
}