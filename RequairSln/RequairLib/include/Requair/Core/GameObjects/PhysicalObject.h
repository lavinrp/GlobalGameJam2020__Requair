#pragma once

#include <Requair/Utils/DllUtils.h>
#include <SFML/System/vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <GameBackbone/Core/Updatable.h>

namespace REQ
{
	class libRequair PhysicalObject : public GB::Updatable
	{
	public:
		PhysicalObject(unsigned int weight);

		// Handle collision between two physical objects
		void Collide(PhysicalObject& other);

		// Set the weight of the object. When objects collide the lighter object will move
		void SetWeight(unsigned int weight) noexcept;

		// Get the weight of the object
		[[nodiscard]]
		int GetWeight() const noexcept;

		// Move the object
		virtual void Translate(sf::Vector2f offset) = 0;

		// Get the bounding box of the Physical object
		virtual sf::FloatRect GetObjectBounds() const = 0;

		// Get the position of the physical object
		virtual sf::Vector2f GetObjectPosition() const = 0;

		// Get the velocity of the physical object pix / second
		const sf::Vector2f& GetVelocity() const noexcept;

		// Set the velocity of the physical object in pix / second
		void SetVelocity(sf::Vector2f velocity);

		// Update the physical object
		void update(sf::Int64 elapsedTime) override;

	private:
		unsigned int m_weight;
		sf::Vector2f m_velocity;
	};

}