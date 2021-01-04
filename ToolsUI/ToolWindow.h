#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "IEventHandler.h"
#include "IRender.h"
#include "TransformUI.h"

namespace editor 
{
	class ToolWindow : public universal::IEventHandler, public universal::IRender
	{
	private:
		std::unique_ptr<sf::RenderWindow> m_window = nullptr;
		std::unique_ptr<TransformUI> m_transformUI = nullptr;
		sf::Event m_event;

	private:
		const sf::Vector2i mousePosWindowSpace();

	public:
		ToolWindow(const sf::Vector2f& position = sf::Vector2f(0.0f, 0.0f));

		void eventHandler() override;
		void render(sf::RenderWindow* window) override;

		void show();
	};
}
