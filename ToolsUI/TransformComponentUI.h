#pragma once
#include <vector>
#include "IRender.h"
#include "TextField.h"

namespace editor
{
	class TransformComponentUI : public universal::IRender
	{
	protected:
		sf::Vector2f m_component = sf::Vector2f(0., 0.0f);
		std::vector<std::unique_ptr<TextField>> m_textFields = std::vector<std::unique_ptr<TextField>>();

	public:
		TransformComponentUI(const sf::Vector2f& component, const sf::Vector2f position = sf::Vector2f(0.0f, 0.0f));

		void render(sf::RenderWindow* window) override;

		void setPosition(const sf::Vector2f& position);

	};
}
