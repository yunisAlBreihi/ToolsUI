#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "WorldObject.h"
#include "IRender.h"
#include "BoxCollider.h"

namespace world 
{
	class Rectangle : public WorldObject, public universal::IRender
	{
	private:
		std::unique_ptr<sf::RectangleShape> m_shape = nullptr;
		std::unique_ptr<universal::BoxCollider> m_collider = nullptr;

	public:
		Rectangle(const sf::Vector2f& size, sf::Color color);

		void render(sf::RenderWindow* window) override;

		const WorldObject* collidingWithPosition(const sf::Vector2f& position);
		const WorldObject* collidingWithPosition(const sf::Vector2i& position);

		void setPosition(const sf::Vector2f& position);
		void setSize(const sf::Vector2f& size);
		const sf::Vector2f& getPosition();
		const sf::Vector2f& getSize();
	};
}