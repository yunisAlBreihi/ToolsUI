#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "IStart.h"
#include "IEventHandler.h"
#include "IUpdate.h"
#include "IRender.h"
#include "IQuit.h"

namespace ToolsUI
{
	class EditorWorld : public IStart, public IEventHandler, public IUpdate, public IRender, public IQuit
	{
	private:
		std::unique_ptr<sf::RenderWindow> m_window = nullptr;
		std::unique_ptr<sf::CircleShape> m_circle = nullptr;

		sf::Event m_event;
		bool m_gameRunning = false;

	public:
		EditorWorld();

		void start() override;
		void eventHandler() override;
		void update() override;
		void render() override;
		void quit() override;

		const bool gameRunning() const { return m_gameRunning; }
	};
}