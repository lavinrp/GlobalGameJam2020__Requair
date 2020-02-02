#include <Requair/Core/GameObjects/PhysicalObject.h>

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
		float unit_vec_norm = velocity_vec.x*velocity_vec.x + velocity_vec.y*velocity_vec.y;
		if (unit_vec_norm > 1.0e-9){
			auto light_postions = lighterObject.GetObjectPosition();
			auto heavy_bounds = heavierObject.GetObjectBounds();
			// find which side I am
			//      1
			//   -----------
			//  2|         |4
			//   |         |
			//   -----------
			//       3
			
			if (light_postions.x <= heavy_bounds.left){
				if(light_postions.y < heavy_bounds.top){
					velocity_vec.y = -velocity_vec.y*0.8;
					velocity_vec.x =  velocity_vec.x*0.8;
				} else if (light_postions.y > (heavy_bounds.top+heavy_bounds.height))
				{
					velocity_vec.y = -velocity_vec.y*0.8;
					velocity_vec.x =  velocity_vec.x*0.8;
				}
				else 
				{
					velocity_vec.x = -velocity_vec.x*0.8;
					velocity_vec.y =  velocity_vec.y*0.8;
				}
				
			} else
			{
				velocity_vec.x = -velocity_vec.x*0.8;
				velocity_vec.y =  velocity_vec.y*0.8;
			}			
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