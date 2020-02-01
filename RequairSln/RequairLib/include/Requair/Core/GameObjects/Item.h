#pragma once

#include <Requair/Core/GameObjects/InteractiveObject.h>
#include <Requair/Core/GameObjects/PhysicalObject.h>

#include <Requair/Utils/DllUtils.h>

namespace REQ
{

	class libRequair Item : public PhysicalObject, public InteractiveObject
	{
	public:
		Item(unsigned int weight);
	};
}