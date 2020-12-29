#pragma once
#include "IEventHandler.h"
#include "IRender.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"

namespace editor 
{
	class ToolWindow : public universal::IEventHandler, public universal::IRender
	{
	private:
		std::unique_ptr<sf::RenderWindow> m_window;

		sf::Event m_event;

	private:
		const sf::Vector2i mousePosWindowSpace();

	public:
		ToolWindow();

		void eventHandler() override;
		void render(sf::RenderWindow* window) override;

		void show();
	};
}
