#include "App.h"
#include "Scenes/MainScene.h"
#include "Globals.h"
App::App()
{
    Globals::Globals();

    createWindow();

    m_sceneManager.setCurrentScene(std::make_unique<MainScene>());
}

App::~App()
{
}

App& App::getInstance()
{
	static App s_appInstance;
	return s_appInstance;
}

StackedEvent& App::getEvents()
{
    return m_events;
}

TimeStep App::getTimeStep() const
{
	return m_timeStep;
}

void App::draw(sf::Drawable& drawable)
{
    m_window.draw(drawable);
}

void App::run()
{
    sf::Clock clock;
    while (m_window.isOpen())
    {
        m_timeStep = clock.restart().asSeconds();

        m_events.clear();
        m_events.captureEvents(m_window);

        for (const auto ev : m_events.getContainer())
        {
            if (ev.type == sf::Event::Closed)
                m_window.close();
        }

        m_sceneManager.update();

        m_window.clear(sf::Color::Black);
        m_sceneManager.draw();
        m_window.display();
    }
}

void App::createWindow()
{
	const char* windowName = "4Uno";
	const uint32_t framerateLimit = 60;
	const sf::Vector2u windowSize{ 800,600 };

	m_window.create(sf::VideoMode(windowSize.x, windowSize.y), windowName, sf::Style::Default);
    m_window.setFramerateLimit(framerateLimit);
}
