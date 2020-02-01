#include <Requair.h>

#include <Requair/Core/EventController.h>

using namespace PT;
Requair::Requair()
{
	// Initialize an instance of DemoCoreEventController
	EventController controller;
	// Start the loop on the DemoCoreEventController to start the Demo
	controller.runLoop();
}