#include <Requair/Core/GameObjects/PhysicalObject.h>

using namespace REQ;

REQ::PhysicalObject::PhysicalObject(unsigned int weight)
{
	m_weight = weight;
}


void REQ::PhysicalObject::SetWeight(unsigned int weight) noexcept
{
	m_weight = weight;
}

int PhysicalObject::GetWeight() const noexcept
{
	return m_weight;
}
