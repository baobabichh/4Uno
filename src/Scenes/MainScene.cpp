#include "MainScene.h"
#include "Lib/Text.h"
#include "Lib/App.h"
#include "SecondScene.h"

void MainScene::update()
{
	for (const auto ev : App::getInstance().getEvents().getContainer())
	{
		if (ev.type == sf::Event::KeyPressed)
		{
			if (ev.key.code == sf::Keyboard::Num2)
			{
				changeScene(new SecondScene());
			}
		}
	}
}

void MainScene::draw()
{
	displayFps();
	displayText("Main scene", 0, 100);
	displayText("Press 2 to go to second scene", 0, 200);
}
