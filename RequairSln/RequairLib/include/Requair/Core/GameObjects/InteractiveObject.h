#pragma once

#include <Requair/Utils/DllUtils.h>
#include <Requair/Core/Boss/Boss.h>

namespace REQ
{

	class libRequair InteractiveObject
	{
	public:
		virtual void Interact(REQ::Boss& boss) = 0;
	};

}