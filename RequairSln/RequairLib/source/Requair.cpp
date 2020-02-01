#include <Requair.h>

#include <Requair/Core/EventController.h>
#include <Requair/Core/Regions/RuntimeRegion.h>
#include <Requair/Core/GameObjects/Pot.h>


using namespace REQ;
Requair::Requair()
{
	// Initialize an instance of DemoCoreEventController
	EventController controller;
	RuntimeRegion testRegion("/home/samee/scratch/ggj_cc/GlobalGameJam2020__Requair/RequairSln/build/bin/levels/level-0.json");

	// Start the loop on the DemoCoreEventController to start the Demo
	controller.runLoop();

}