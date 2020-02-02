#include <Requair.h>

#include <Requair/Core/EventController.h>
#include <Requair/Core/GameObjects/Pot.h>


using namespace REQ;
Requair::Requair()
{
	// Initialize an instance of DemoCoreEventController
	EventController controller;

	// Start the loop on the DemoCoreEventController to start the Demo
	controller.runLoop();

}