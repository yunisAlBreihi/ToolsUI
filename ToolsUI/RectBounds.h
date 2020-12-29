#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "IRender.h"

namespace universal 
{
	class RectBounds : public IRender
	{
	private:
		std::unique_ptr<sf::RectangleShape> m_shape = nullptr;
		sf::Vector2f m_position = sf::Vector2f(0, 0);
		sf::Vector2f m_size = sf::Vector2f(0, 0);
		bool m_drawShape = false;

	public:
		RectBounds(const sf::Vector2f position, const sf::Vector2f size);

		void render(sf::RenderWindow* window) override;

		const sf::Vector2f& getPosition() const;
		const sf::Vector2f& getSize() const;
		void setPosition(const sf::Vector2f& position);
		void setSize(const sf::Vector2f& size);
		void setDrawShape(bool draw);

		void setColor(const sf::Color& color);
	};
}