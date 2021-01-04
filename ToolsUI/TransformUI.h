#pragma once
#include "IRender.h"
#include "TransformComponentUI.h"

namespace editor 
{
	class TransformUI : public universal::IRender
	{
	private:
		std::unique_ptr<sf::RectangleShape> m_body = nullptr;

		std::vector<TransformComponentUI> m_transformComponents = std::vector<TransformComponentUI>();

	public:
		TransformUI(const sf::Vector2f& position, const sf::Vector2f& size);

		void render(sf::RenderWindow* window) override;

	};
}
