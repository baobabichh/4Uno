#include "StackedEvent.h"

StackedEvent::StackedEvent()
{
	m_events.reserve(10);
}

void StackedEvent::captureEvents(sf::RenderWindow& window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		m_events.push_back(event);
	}
}

void StackedEvent::clear()
{
	if (m_events.size())
		m_events.clear();
}

size_t StackedEvent::size()const
{
	return m_events.size();
}

const std::vector<sf::Event>& StackedEvent::getContainer()const
{
	return m_events;
}

const sf::Event& StackedEvent::operator[](size_t index)const
{
	if (index >= 0 && index < m_events.size())
		throw "Stacked event out of range\n";
	return m_events[index];
}
