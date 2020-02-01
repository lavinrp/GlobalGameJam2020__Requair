#pragma once

#include <Requair/Utils/DllUtils.h>
#include <SFML/System/vector2.hpp>

namespace REQ
{
	class libRequair PhysicalObject
	{
	public:
		PhysicalObject(unsigned int weight);

		virtual void Collide(PhysicalObject& other) = 0;
		void SetWeight(unsigned int weight) noexcept;
		[[nodiscard]]
		int GetWeight() const noexcept;
	private:
		unsigned int m_weight;
	};

}