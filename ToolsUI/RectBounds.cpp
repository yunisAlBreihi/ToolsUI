#include "RectBounds.h"

namespace universal
{
	RectBounds::RectBounds(const sf::Vector2f position, const sf::Vector2f size) : m_position(position), m_size(size)
	{
		m_shape = std::make_unique<sf::RectangleShape>(size);
		m_shape->setPosition(m_position);
		m_shape->setOutlineThickness(2.0f);
		m_shape->setOutlineColor(sf::Color::Red);
	}

	void RectBounds::render(sf::RenderWindow* window)
	{
		if (m_drawShape == true) {
			window->draw(*m_shape);
		}
	}

	const sf::Vector2f& RectBounds::getPosition() const
	{
		return m_position;
	}

	void RectBounds::setPosition(const sf::Vector2f& position)
	{
		m_position = position;
		m_shape->setPosition(m_position);
	}

	const sf::Vector2f& RectBounds::getSize() const
	{
		return m_size;
	}

	void RectBounds::setSize(const sf::Vector2f& size)
	{
		m_size = size;
		m_shape->setSize(m_size);
	}

	void RectBounds::setDrawShape(bool draw)
	{
		m_drawShape = draw;
	}

	void RectBounds::setColor(const sf::Color& color)
	{
		m_shape->setOutlineColor(color);
	}
}