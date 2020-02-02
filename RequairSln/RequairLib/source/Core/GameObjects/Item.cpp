#include <Requair/Core/GameObjects/Item.h>

using namespace REQ;

Item::Item(unsigned int weight) : PhysicalObject(weight) {}

bool Item::IsCollectible() {
	return false;
}
