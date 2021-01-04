#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "IStart.h"
#include "IEventHandler.h"
#include "IUpdate.h"
#include "IRender.h"
#include "IQuit.h"
#include "Rectangle.h"
#include "ToolWindow.h"

namespace editor
{
	class EditorWorld
	{
	private:
		std::unique_ptr<sf::RenderWindow> m_window = nullptr;
		std::unique_ptr<world::Rectangle> m_rectangle = nullptr;

		std::vector<std::unique_ptr<world::WorldObject>> m_worldObjects;
		//std::vector<std::unique_ptr<world::WorldObject>> selectedObjects;
		std::unique_ptr<world::WorldObject> m_currentSelection = nullptr;

		std::unique_ptr<ToolWindow> m_toolWindow;

		sf::Event m_event;
		bool m_gameRunning = false;
		bool m_holdingLMB = false;

	public:
		EditorWorld();

		void start();
		void eventHandler();
		void update();
		void render();
		void quit();

		const bool gameRunning() const { return m_gameRunning; }
		const sf::Vector2i mousePosWindowSpace();

		const bool selectObject(world::WorldObject* object);
	};
}