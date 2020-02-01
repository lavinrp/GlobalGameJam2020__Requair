#include <Requair/Core/GameObjects/PhysicalObject.h>

using namespace REQ;

PhysicalObject::PhysicalObject(unsigned int weight)
{
	m_weight = weight;
}

void PhysicalObject::Collide(PhysicalObject& other)
{
	PhysicalObject& lighterObject = this->GetWeight() < other.GetWeight() ? *this : other;
	while (other.GetObjectBounds().intersects(this->GetObjectBounds()) || 
		other.GetObjectBounds().contains(this->GetObjectPosition()))
	{
		// TODO: Get Unit Vector and Translate the lighter object out of the heavy one
		// TODO: handle velocity and bouncing
	}
}

void PhysicalObject::SetWeight(unsigned int weight) noexcept
{
	m_weight = weight;
}

int PhysicalObject::GetWeight() const noexcept
{
	return m_weight;
}


const sf::Vector2f& PhysicalObject::GetVelocity() const noexcept
{
	return m_velocity;
}

void PhysicalObject::SetVelocity(sf::Vector2f velocity)
{
	m_velocity = std::move(velocity);
}

void PhysicalObject::update(sf::Int64 elapsedTime)
{
	const float timeModifier = elapsedTime / 1000.0f; // milliseconds to seconds
	sf::Vector2f offset = { m_velocity.x * timeModifier, m_velocity.y * timeModifier };
	Translate(offset);
}