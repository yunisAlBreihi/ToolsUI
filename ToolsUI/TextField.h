#pragma once
#include <memory>
#include "IRender.h"

namespace editor
{
	class TextField : public universal::IRender
	{
	private:
		std::unique_ptr<sf::RectangleShape> m_componentField = nullptr;

		float m_componentValue = 0.0f;

		sf::Text m_text;
		sf::Font m_font;

	public:
		TextField(const sf::Vector2f& size = sf::Vector2f(0.0f, 0.0f),
			const float& componentValue = 0.0f,
			const sf::Vector2f& position = sf::Vector2f(0.0f, 0.0f));

		void render(sf::RenderWindow* window) override;

		void setPosition(const sf::Vector2f& position);
		const sf::Vector2f getPosition() const;
		void setSize(const sf::Vector2f& size, const float& fontSize);
		const sf::Vector2f getSize() const;

		void setComponentValue(const float& value);
	};
}
