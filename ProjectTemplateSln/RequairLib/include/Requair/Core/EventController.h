#pragma once

#include <Requair/Utils/DllUtils.h>
#include <Requair/Core/Regions/TemplateRegion.h>

#include <GameBackbone/Core/CoreEventController.h>


namespace PT
{
	class libRequair EventController final : public GB::CoreEventController
	{
	public:
		// Constructors
		EventController();
		EventController(const EventController& other) = delete;
		EventController(EventController&& other) = default;
		EventController& operator=(const EventController& other) = delete;
		EventController& operator=(EventController&& other) = default;
		virtual ~EventController() = default;

		// Event handling
		void handleEvent(sf::Event& event) override;

	private:
		sf::View camera;
		TemplateRegion mainRegion;
	};
}
