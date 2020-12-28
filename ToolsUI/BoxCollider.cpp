#include "BoxCollider.h"

namespace universal 
{
	BoxCollider::BoxCollider(const sf::Vector2f position, const sf::Vector2f size) : m_position(position), m_size(size)
	{
		m_shape = std::make_unique<sf::RectangleShape>(size);
		m_shape->setOutlineThickness(2.0f);
		m_shape->setOutlineColor(sf::Color::Red);
	}

	void BoxCollider::render(sf::RenderWindow* window)
	{
		if (m_drawShape == true) {
			window->draw(*m_shape);
		}
	}

	void BoxCollider::setPosition(const sf::Vector2f& position)
	{
		m_position = position;
		if (m_drawShape == true) {
			m_shape->setPosition(m_position);
		}
	}

	void BoxCollider::setSize(const sf::Vector2f& size)
	{
		m_size = size;
		if (m_drawShape == true) {
			m_shape->setSize(m_size);
		}
	}

	void BoxCollider::setDebugColor(const sf::Color& color)
	{
		if (m_drawShape == true) {
			m_shape->setOutlineColor(color);
		}
	}

	bool BoxCollider::collidingWithPosition(const sf::Vector2f& position) const
	{
		bool left = position.x > m_position.x;
		bool right = position.x < m_position.x + m_size.x;
		bool top = position.y > m_position.y;
		bool bot = position.y < m_position.y + m_size.y;

		if (left == true && right == true && top == true && bot == true) {
			m_shape->setOutlineColor(sf::Color::Green);
			return true;
		}

		m_shape->setOutlineColor(sf::Color::Red);
		return false;
	}

	bool BoxCollider::collidingWithPosition(const sf::Vector2i& position) const
	{
		bool left = position.x > m_position.x;
		bool right = position.x < m_position.x + m_size.x;
		bool top = position.y > m_position.y;
		bool bot = position.y < m_position.y + m_size.y;

		if (left == true && right == true && top == true && bot == true) {
			m_shape->setOutlineColor(sf::Color::Green);
			return true;
		}

		m_shape->setOutlineColor(sf::Color::Red);
		return false;
	}
}