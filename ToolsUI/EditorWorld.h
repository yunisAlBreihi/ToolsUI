#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "IStart.h"
#include "IEventHandler.h"
#include "IUpdate.h"
#include "IRender.h"
#include "IQuit.h"
#include "Rectangle.h"

namespace universal
{
	class EditorWorld
	{
	private:
		std::unique_ptr<sf::RenderWindow> m_window = nullptr;
		std::unique_ptr<world::Rectangle> m_rectangle = nullptr;

		std::vector<std::unique_ptr<world::WorldObject>> worldObjects;
		std::unique_ptr<world::WorldObject> m_currentSelection = nullptr;

		sf::Event m_event;
		bool m_gameRunning = false;

	public:
		EditorWorld();

		void start();
		void eventHandler();
		void update();
		void render();
		void quit();

		const bool gameRunning() const { return m_gameRunning; }
		const sf::Vector2i mousePosWindowSpace();
	};
}