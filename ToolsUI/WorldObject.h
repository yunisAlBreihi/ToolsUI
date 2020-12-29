#pragma once
#include "IRender.h"
#include "RectBounds.h"

namespace world 
{
	class WorldObject : public universal::IRender {
	protected:
		std::unique_ptr<universal::RectBounds> m_bounds = nullptr;
		sf::Vector2f m_position = sf::Vector2f(0, 0);
		sf::Vector2f m_size = sf::Vector2f(0, 0);

	public:
		WorldObject(const sf::Vector2f& position, const sf::Vector2f& size);

		virtual void setPosition(const sf::Vector2f& position);
		virtual void setSize(const sf::Vector2f& size);
		void setBoundsColor(const sf::Color& color);
		const sf::Vector2f& getPosition() const;
		const sf::Vector2f& getSize() const;
		const sf::Vector2f& getBoundsPosition() const;
		const sf::Vector2f& getBoundsSize() const;
	};
}