#include "TextField.h"
#include "globals.h"

namespace editor
{
	TextField::TextField(const sf::Vector2f& size, const float& componentValue, const sf::Vector2f& position) : m_componentValue(componentValue)
	{
		m_componentField = std::make_unique<sf::RectangleShape>(size);
		m_componentField->setFillColor(sf::Color::White);
		m_componentField->setPosition(position);

		m_font = sf::Font();
		m_font.loadFromFile("arial.ttf");
		m_text = sf::Text(globals::floatToStringPrecision(0.0f, 3), m_font, size.y);
		m_text.setPosition(sf::Vector2f(position));
		m_text.setFillColor(sf::Color::Black);
	}

	void TextField::render(sf::RenderWindow* window)
	{
		window->draw(*m_componentField);
		window->draw(m_text);
	}

	void TextField::setPosition(const sf::Vector2f& position)
	{
		m_componentField->setPosition(position);
		m_text.setPosition(position);
	}

	const sf::Vector2f TextField::getPosition() const
	{
		return m_componentField->getPosition();
		return sf::Vector2f();
	}

	void TextField::setSize(const sf::Vector2f& size, const float& fontSize)
	{
		m_componentField->setSize(size);
		m_text.setCharacterSize(fontSize);
	}

	const sf::Vector2f TextField::getSize() const
	{
		return m_componentField->getSize();
		return sf::Vector2f();
	}

	void TextField::setComponentValue(const float& value)
	{
		m_text.setString(globals::floatToStringPrecision(value, 3));
	}
}