#pragma once
#include <SFML/Graphics.hpp>

namespace card
{
	class MyDrawable
	{
	public:
		virtual ~MyDrawable() = default;
		virtual void draw(sf::RenderStates states = sf::RenderStates::Default) = 0;
	};
}
