#include "EditorWorld.h"

namespace ToolsUI
{
	ToolsUI::EditorWorld::EditorWorld() {
		m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1280, 720), "ToolsUI!");
		m_gameRunning = true;
	}

	void EditorWorld::start()
	{
		//Create a circle
		m_circle = std::make_unique<sf::CircleShape>(100.0f);
		m_circle->setFillColor(sf::Color::Green);
	}

	void EditorWorld::eventHandler()
	{
		if (m_window->pollEvent(m_event) == true) {
			if (m_event.type == sf::Event::Closed) {
				m_window->close();
				m_gameRunning = false;
			}
		}
	}

	void EditorWorld::update()
	{
		std::vector<IUpdate*> updateableObjects;

		//Add update of objects here
		for (const auto& updatable : updateableObjects) {
			updatable->update();
		}
	}

	void EditorWorld::render()
	{
		m_window->clear();

		//Add items to render here
		m_window->draw(*m_circle);

		m_window->display();
	}

	void EditorWorld::quit()
	{
		//garbage collection and things that need clean up here
	}
}