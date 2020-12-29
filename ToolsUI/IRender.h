#pragma once
#include <SFML/Graphics.hpp>

namespace universal 
{
	class IRender 
	{
	public:
		virtual void render(sf::RenderWindow* window) = 0;
	};
}