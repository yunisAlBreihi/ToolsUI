#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "WorldObject.h"
#include "IRender.h"
#include "RectBounds.h"

namespace world 
{
	class Rectangle : public WorldObject
	{
	private:
		std::unique_ptr<sf::RectangleShape> m_shape = nullptr;

	public:
		Rectangle(const sf::Color& color, const sf::Vector2f& position = sf::Vector2f(0,0), const sf::Vector2f& size = sf::Vector2f(0,0));

		void render(sf::RenderWindow* window) override;

		void setPosition(const sf::Vector2f& position) override;
		void setSize(const sf::Vector2f& size) override;
	};
}