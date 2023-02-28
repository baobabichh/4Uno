#pragma once
#include <SFML/Graphics.hpp>
#include <Lib/StackedEvent.h>
#include <lib/SceneManager.h>

typedef float TimeStep;


class App
{
public:
	App();
	~App();
	static App& getInstance();

	StackedEvent& getEvents();
	TimeStep getTimeStep()const;
	void draw(sf::Drawable& drawable);

	void run();

private:
	sf::RenderWindow m_window;
	TimeStep m_timeStep;
	StackedEvent m_events;
	SceneManager m_sceneManager;

private:
	void createWindow();
};
