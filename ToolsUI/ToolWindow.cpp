#include "ToolWindow.h"

namespace editor 
{
	ToolWindow::ToolWindow()
	{
		m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(500, 720), "Inspector");
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
		m_window->clear();

		//Add items to render here

		m_window->display();
	}

	void ToolWindow::show()
	{
		m_window->create(sf::VideoMode(500, 720), "Inspector");
	}

	const sf::Vector2i ToolWindow::mousePosWindowSpace()
	{
		//the extra 30.0f in "y" is compensate for the the window top ribbon
		return sf::Vector2i(sf::Mouse::getPosition().x - m_window->getPosition().x,
							sf::Mouse::getPosition().y - m_window->getPosition().y - 30.0f);
	}
}