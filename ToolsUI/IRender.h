#pragma once

namespace universal 
{
	class IRender 
	{
	public:
		virtual void render(sf::RenderWindow* window) = 0;
	};
}