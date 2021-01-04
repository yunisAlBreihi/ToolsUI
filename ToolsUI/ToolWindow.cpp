#include "ToolWindow.h"
#include <string>
#include <iostream>

namespace editor
{
	ToolWindow::ToolWindow(const sf::Vector2f& position)
	{
		m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(500, 720), "Inspector");
		m_transformUI = std::make_unique<TransformUI>(sf::Vector2f(20.0f, 20.0f),sf::Vector2f(200.0f, 200.0f));
	}

	void ToolWindow::eventHandler()
	{
		if (m_window->pollEvent(m_event) == true) {
			if (m_event.type == sf::Event::Closed) {
				m_window->close();
			}
		}
	}

	void ToolWindow::render(sf::RenderWindow* window)
	{
		m_window->clear(sf::Color(128, 128, 128, 255));

		//Add items to render here
		m_transformUI->render(&*m_window);

		m_window->display();
	}

	void ToolWindow::show()
	{
		if (m_window->isOpen() == false) {
			m_window->create(sf::VideoMode(500, 720), "Inspector");
		}
	}

	const sf::Vector2i ToolWindow::mousePosWindowSpace()
	{
		//the extra 30.0f in "y" is compensate for the the window top ribbon
		return sf::Vector2i(sf::Mouse::getPosition().x - m_window->getPosition().x,
			sf::Mouse::getPosition().y - m_window->getPosition().y - 30.0f);
	}
}