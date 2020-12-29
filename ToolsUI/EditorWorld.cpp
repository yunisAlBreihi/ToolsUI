#include "EditorWorld.h"
#include <iostream>
#include <SFML/Window/Mouse.hpp>

namespace editor
{
	EditorWorld::EditorWorld()
	{
		m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1280, 720), "ToolsUI!");
		m_gameRunning = true;
	}

	void EditorWorld::start()
	{
		m_rectangle = std::make_unique<world::Rectangle>(sf::Color::Cyan, sf::Vector2f(0, 0), sf::Vector2f(100, 100));
		worldObjects.emplace_back(std::move(m_rectangle));
		m_rectangle = std::make_unique<world::Rectangle>(sf::Color::Cyan, sf::Vector2f(200, 200), sf::Vector2f(100, 100));
		worldObjects.emplace_back(std::move(m_rectangle));
	}

	void EditorWorld::eventHandler()
	{
		if (m_window->pollEvent(m_event) == true) {
			if (m_event.type == sf::Event::Closed) {
				m_window->close();
				m_gameRunning = false;
			}

			//TODO: Make mouse press only once
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true && m_holdingLMB == false) {
				m_holdingLMB = true;

				for(auto& obj : worldObjects) {
					if (m_currentSelection != nullptr) {
						worldObjects.emplace_back(std::move(m_currentSelection));
					}
					if (selectObject(&(*obj))) {
						m_currentSelection = std::move(obj);
						break;
					}
				}

				if (m_currentSelection != nullptr) 	{
					if (m_toolWindow == nullptr) {
						m_toolWindow = std::make_unique<ToolWindow>();
					}
					else {
						m_toolWindow->show();
					}
				}
			}
		}
	}

	void EditorWorld::update()
	{
		//Add update of objects here
	}

	void EditorWorld::render()
	{
		m_window->clear();

		//Add items to render here
		for (const auto& obj : worldObjects) {
			obj->render(&(*m_window));
		}

		m_window->display();
	}

	void EditorWorld::quit()
	{
		//garbage collection and things that need clean up here
	}

	const sf::Vector2i EditorWorld::mousePosWindowSpace()
	{
		//the extra 30.0f in "y" is compensate for the the window top ribbon
		return sf::Vector2i(sf::Mouse::getPosition().x - m_window->getPosition().x,
							sf::Mouse::getPosition().y - m_window->getPosition().y - 30.0f);
	}

	const bool EditorWorld::selectObject(world::WorldObject* object)
	{
		bool left = mousePosWindowSpace().x > object->getBoundsPosition().x;
		bool right = mousePosWindowSpace().x < object->getBoundsPosition().x + object->getBoundsSize().x;
		bool top = mousePosWindowSpace().y > object->getBoundsPosition().y;
		bool bot = mousePosWindowSpace().y < object->getBoundsPosition().y + object->getBoundsSize().y;

		if (left == true && right == true && top == true && bot == true) {
			object->setBoundsColor(sf::Color::Green);
			return true;
		}
		return false;
	}
}