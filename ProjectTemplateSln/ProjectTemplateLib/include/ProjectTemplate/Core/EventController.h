#pragma once

#include <ProjectTemplate/Utils/DllUtils.h>
#include <ProjectTemplate/Core/TemplateRegion.h>

#include <GameBackbone/Core/CoreEventController.h>


namespace PT
{
	class libProjectTemplate EventController final : public GB::CoreEventController
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
