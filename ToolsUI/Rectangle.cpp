#include "Rectangle.h"

namespace world
{
	Rectangle::Rectangle(const sf::Color& color, const sf::Vector2f& position, const sf::Vector2f& size) : WorldObject(position, size)
	{
		m_shape = std::make_unique<sf::RectangleShape>(size);
		m_shape->setPosition(position);
		m_shape->setFillColor(color);
		m_bounds->setDrawShape(true);
	}

	void Rectangle::render(sf::RenderWindow* window)
	{
		window->draw((*m_shape));
		m_bounds->render(window);
	}

	void Rectangle::setPosition(const sf::Vector2f& position)
	{
		m_shape->setPosition(position);
		m_bounds->setPosition(position);
	}

	void Rectangle::setSize(const sf::Vector2f& size)
	{
		m_shape->setSize(size);
		m_bounds->setSize(size);
	}
}