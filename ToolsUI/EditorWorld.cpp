#include "EditorWorld.h"
#include <iostream>
#include <SFML/Window/Mouse.hpp>

namespace universal
{
	universal::EditorWorld::EditorWorld() {
		m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1280, 720), "ToolsUI!");
		m_gameRunning = true;
	}

	void EditorWorld::start()
	{
		//m_rectangle = ;
		//m_rectangle->setPosition(sf::Vector2f(50,50));
		worldObjects.emplace_back(std::make_unique<world::Rectangle>(sf::Vector2f(100, 100), sf::Color::Cyan));
	}

	void EditorWorld::eventHandler()
	{
		if (m_window->pollEvent(m_event) == true) {
			if (m_event.type == sf::Event::Closed) {
				m_window->close();
				m_gameRunning = false;
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true)
			{
				for(const auto& obj : worldObjects)
				{
				}
			}
		}

		//std::cout << "rectangle pos: " << m_rectangle->getPosition().x << " , " << m_rectangle->getPosition().y << '\n';
		//std::cout << "mouse pos: " << mousePosWindowSpace().x << " , " << mousePosWindowSpace().y << '\n';

		//sf::Vector2f t_mousePos = sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);

		

		if (m_rectangle->collidingWithPosition(mousePosWindowSpace())) {
			std::cout << "mouse colliding" << '\n';
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
		//m_window->draw(*(m_rectangle->getShape()));
		m_rectangle->render(&(*m_window));

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
}