#include "TransformComponentUI.h"

namespace editor
{
	TransformComponentUI::TransformComponentUI(const sf::Vector2f& component, const sf::Vector2f position) : m_component(component)
	{
		m_textFields.emplace_back(std::move(std::make_unique<TextField>(sf::Vector2f(60, 20))));
		m_textFields.emplace_back(std::move(std::make_unique<TextField>(sf::Vector2f(60, 20))));
	}

	void TransformComponentUI::render(sf::RenderWindow* window)
	{
		for (auto& textField : m_textFields) {
			textField->render(window);
		}
	}

	void TransformComponentUI::setPosition(const sf::Vector2f& position)
	{
		for (size_t i = 0; i < m_textFields.size(); ++i) {
			sf::Vector2f t_pos = sf::Vector2f(position.x + (i * 100), position.y);
			m_textFields[i]->setPosition(t_pos);
		}
	}
}