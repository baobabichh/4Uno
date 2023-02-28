#pragma once

#include "SFML/Graphics.hpp"
#include <vector>

class StackedEvent
{
public:
	StackedEvent();
	~StackedEvent() = default;
	void captureEvents(sf::RenderWindow& window);
	void clear();
	size_t size()const;
	const std::vector <sf::Event>& getContainer()const;
	const sf::Event& operator[](size_t index)const;

private:
	std::vector <sf::Event> m_events;
};



