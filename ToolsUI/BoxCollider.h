#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "IRender.h"

namespace universal 
{
	class BoxCollider : public IRender
	{
	private:
		std::unique_ptr<sf::RectangleShape> m_shape = nullptr;
		sf::Vector2f m_position = sf::Vector2f(0, 0);
		sf::Vector2f m_size = sf::Vector2f(0, 0);

	public:
		bool m_drawShape = false;

	public:
		BoxCollider(const sf::Vector2f position, const sf::Vector2f size);

		void render(sf::RenderWindow* window) override;

		void setPosition(const sf::Vector2f& position);
		void setSize(const sf::Vector2f& size);

		void setDebugColor(const sf::Color& color);

		bool collidingWithPosition(const sf::Vector2f& position) const;
		bool collidingWithPosition(const sf::Vector2i& position) const;
	};
}