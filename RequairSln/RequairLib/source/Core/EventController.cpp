#include <Requair/Core/EventController.h>

#include <Requair/Core/Regions/BossRegion.h>

#include <string>
#include <iostream>

using namespace REQ;

#define APP_NAME "Requair"

EventController::EventController() : CoreEventController(APP_NAME), mainRegion(std::make_unique<BossRegion>("Levels/level-0.json"))
{
	// Set the camera to the same as the window
	camera.reset(sf::FloatRect(0, 0, (float)getWindow().getSize().x, (float)getWindow().getSize().y));
	setActiveRegion(mainRegion.get());
}

void EventController::handleEvent(sf::Event & event)
{
	static_cast<TemplateRegion*>(getActiveRegion())->HandleEvent(event);
}