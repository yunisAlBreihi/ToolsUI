#include "WorldObject.h"

namespace world
{
	WorldObject::WorldObject(const sf::Vector2f& position, const sf::Vector2f& size) : m_position(position), m_size(size)
	{
		m_bounds = std::make_unique<universal::RectBounds>(m_position, m_size);
	}

	void WorldObject::setPosition(const sf::Vector2f& position)
	{
		m_position = position;
		m_bounds->setPosition(position);
	}

	void WorldObject::setSize(const sf::Vector2f& size)
	{
		m_size = size;
		m_bounds->setSize(size);
	}

	void WorldObject::setBoundsColor(const sf::Color& color)
	{
		m_bounds->setColor(color);
	}

	const sf::Vector2f& WorldObject::getPosition() const
	{
		return m_position;
	}

	const sf::Vector2f& WorldObject::getSize() const
	{
		return m_size;
	}

	const sf::Vector2f& WorldObject::getBoundsPosition() const
	{
		return m_bounds->getPosition();
	}
	const sf::Vector2f& WorldObject::getBoundsSize() const
	{
		return m_bounds->getSize();
	}
}