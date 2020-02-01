#pragma once

#include <Requair/Utils/DllUtils.h>
#include <Requair/Core/GameObjects/Item.h>
#include <Requair/Core/GameObjects/AnimatedItem.h>


namespace REQ
{
	class libRequair Pot : public AnimatedItem
	{
	public:
		Pot(float x, float y);

		void Interact() override;

	private:
		bool m_broken;
	};
}