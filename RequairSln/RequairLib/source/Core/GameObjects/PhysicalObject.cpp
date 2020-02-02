#include <Requair/Core/GameObjects/PhysicalObject.h>
#include <cmath>

using namespace REQ;

PhysicalObject::PhysicalObject(unsigned int weight)
{
	m_weight = weight;
}

void PhysicalObject::Collide(PhysicalObject& other)
{
	PhysicalObject& lighterObject = this->GetWeight() < other.GetWeight() ? *this : other;
	PhysicalObject& heavierObject = this->GetWeight() > other.GetWeight() ? *this : other;
	if (other.GetObjectBounds().intersects(this->GetObjectBounds()) ||
		other.GetObjectBounds().contains(this->GetObjectPosition()))
	{
		sf::Vector2f velocity_vec = lighterObject.GetVelocity();
		float unit_vec_norm = velocity_vec.x * velocity_vec.x + velocity_vec.y * velocity_vec.y;
		float scale_unit_translate(1.0);
		if (unit_vec_norm > 1.0e-9) {
			auto light_postions = lighterObject.GetObjectPosition();
			auto heavy_bounds = heavierObject.GetObjectBounds();
			scale_unit_translate = 0.01 * std::max(heavy_bounds.height, heavy_bounds.width);
			// find which side I am
			//      1
			//   -----------
			//  2|         |4
			//   |         |
			//   -----------
			//       3


			if (light_postions.x < heavy_bounds.left) {
				if (light_postions.y < heavy_bounds.top) {
					velocity_vec.x = velocity_vec.x * 0.8;
					velocity_vec.y = -velocity_vec.y * 0.8;
				}
				else if (abs(light_postions.y - (heavy_bounds.top + heavy_bounds.height)) < 1.0)
				{
					velocity_vec.x = velocity_vec.x * 0.8;
					velocity_vec.y = -velocity_vec.y * 0.8;
				}
				else
				{
					velocity_vec.x = -velocity_vec.x * 0.8;
					velocity_vec.y = velocity_vec.y * 0.8;
				}

			}
			else if (abs(light_postions.x - (heavy_bounds.left + heavy_bounds.width)) < 1.0)
			{
				if (light_postions.y < heavy_bounds.top) {
					velocity_vec.y = -velocity_vec.y * 0.8;
					velocity_vec.x = velocity_vec.x * 0.8;
				}
				else if (abs(light_postions.y - (heavy_bounds.top + heavy_bounds.height)) < 1.0)
				{
					velocity_vec.y = -velocity_vec.y * 0.8;
					velocity_vec.x = velocity_vec.x * 0.8;
				}
				else
				{
					velocity_vec.x = -velocity_vec.x * 0.8;
					velocity_vec.y = velocity_vec.y * 0.8;
				}
			}
			else
				if (light_postions.y < heavy_bounds.top) {
					velocity_vec.y = -velocity_vec.y * 0.8;
					velocity_vec.x = velocity_vec.x * 0.8;
				}
				else if (abs(light_postions.y - (heavy_bounds.top + heavy_bounds.height)) < 1.0)
				{
					velocity_vec.y = -velocity_vec.y * 0.8;
					velocity_vec.x = velocity_vec.x * 0.8;
				}
				else
				{
					velocity_vec.x = -velocity_vec.x * 0.8;
					velocity_vec.y = velocity_vec.y * 0.8;
				}
			sf::Vector2f unit_translate(scale_unit_translate * velocity_vec.x / unit_vec_norm, scale_unit_translate * velocity_vec.y / unit_vec_norm);
			lighterObject.Translate(unit_translate);
		}

		lighterObject.SetVelocity(velocity_vec);
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