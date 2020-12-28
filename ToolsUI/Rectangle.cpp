#include "Rectangle.h"

namespace world
{
	Rectangle::Rectangle(const sf::Vector2f& size, sf::Color color)
	{
		m_shape = std::make_unique<sf::RectangleShape>(size);
		m_shape->setFillColor(color);
		m_collider = std::make_unique<universal::BoxCollider>(m_shape->getPosition(), m_shape->getSize());
		m_collider->m_drawShape = true;
	}

	void Rectangle::render(sf::RenderWindow* window)
	{
		window->draw((*m_shape));
		m_collider->render(window);
	}

	const WorldObject* Rectangle::collidingWithPosition(const sf::Vector2f& position)
	{
		if (m_collider->collidingWithPosition(position) == true) {
			return this;
		}
		return nullptr;
	}

	const WorldObject* Rectangle::collidingWithPosition(const sf::Vector2i& position)
	{
		if (m_collider->collidingWithPosition(position) == true) {
			return this;
		}
		return nullptr;
	}

	void Rectangle::setPosition(const sf::Vector2f& position)
	{
		m_shape->setPosition(position);
		m_collider->setPosition(position);
	}

	const sf::Vector2f& Rectangle::getPosition()
	{
		return m_shape->getPosition();
	}

	void Rectangle::setSize(const sf::Vector2f& size)
	{
		m_shape->setSize(size);
		m_collider->setSize(size);
	}

	const sf::Vector2f& Rectangle::getSize()
	{
		return m_shape->getSize();
	}
}