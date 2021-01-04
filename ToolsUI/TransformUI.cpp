#include "TransformUI.h"

namespace editor 
{
	TransformUI::TransformUI(const sf::Vector2f& position, const sf::Vector2f& size)
	{
		m_body = std::make_unique<sf::RectangleShape>(size);
		m_body->setPosition(position);
		m_body->setFillColor(sf::Color(0, 0, 0, 0));
		m_body->setOutlineThickness(2.0f);
		m_body->setOutlineColor(sf::Color::Black);

		m_transformComponents.push_back(std::move(TransformComponentUI(sf::Vector2f())));
		m_transformComponents.push_back(std::move(TransformComponentUI(sf::Vector2f())));

		for (size_t i = 0; i < m_transformComponents.size(); ++i) {
			m_transformComponents[i].setPosition(sf::Vector2f(position.x, position.y + (i * 50)));
		}
	}

	void TransformUI::render(sf::RenderWindow* window)
	{
		for (auto& t_component : m_transformComponents)	{
			t_component.render(window);
		}
		window->draw(*m_body);
	}

}

