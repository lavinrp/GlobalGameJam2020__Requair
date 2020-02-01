#include <Requair/Core/EventController.h>

#include <Requair/Core/Regions/BossRegion.h>

#include <string>
#include <iostream>

using namespace REQ;

#define APP_NAME "Requair"

EventController::EventController() : CoreEventController(APP_NAME), mainRegion(std::make_unique<BossRegion>(""))
{
	// Set the camera to the same as the window
	camera.reset(sf::FloatRect(0, 0, (float)getWindow().getSize().x, (float)getWindow().getSize().y));
	setActiveRegion(mainRegion.get());
}

void EventController::handleEvent(sf::Event & event)
{
	static_cast<BossRegion*>(getActiveRegion())->HandleEvent(event);
	// std::cout << "Hello";

	//if (sf::Event::KeyPressed) {
	//	if (event.key.code == 71 || event.key.code == 72 || 
	//		event.key.code == 73 || event.key.code == 74) {

	//		std::cout << event.key.code;
	//		std::cout << " ";
	//	}
	//	else {

	//		std::cout << ".";
	//	}

	//	// std::cout << event.key.code;
	//}

	// Handle events not handled by the GUI
	//switch (event.type) 
	//{
	//	case sf::Event::Closed:
	//	{
	//		// Close the window, thus closing the game.
	//		getWindow().close();
	//		return;
	//	}
	//	case sf::Event::MouseMoved:
	//	{
	//		// Get the pixel position and map it to coordinates
	//		sf::Vector2i mousePos(event.mouseMove.x, event.mouseMove.y);
	//		sf::Vector2f actualPosition = getWindow().mapPixelToCoords(mousePos);
	//		// Pass the event to the active region to handle
	//		return;
	//	}
	//	case sf::Event::MouseButtonPressed:
	//	{
	//		// Get the pixel position and map it to coordinates
	//		sf::Vector2i mousePos(event.mouseButton.x, event.mouseButton.y);
	//		sf::Vector2f actualPosition = getWindow().mapPixelToCoords(mousePos);
	//		// Pass the event to the active region to handle
	//		return;
	//	}
	//	case sf::Event::MouseWheelScrolled:
	//	{
	//		// Pass the event to the active region to handle
	//		return;
	//	}
	//	case sf::Event::KeyPressed:
	//	{
	//		// Pass the event to the active region to handle
	//		return;
	//	}
	//	case sf::Event::KeyReleased:
	//	{
	//		// Pass the event to the active region to handle
	//		return;
	//	}
	//	case sf::Event::Resized:
	//	{
	//		// Reset the camera to the same as the window
	//		camera.reset(sf::FloatRect(0, 0, (float)event.size.width, (float)event.size.height));
	//		// Set the view on the window to be the reset camera
	//		getWindow().setView(camera);
	//		return;
	//	}
	//	default:
	//	{
	//		return;
	//	}
	//}
}