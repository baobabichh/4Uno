#include "SecondScene.h"
#include "Lib/Text.h"
#include "Lib/App.h"
#include "MainScene.h"

void SecondScene::update()
{
	for (const auto ev : App::getInstance().getEvents().getContainer())
	{
		if (ev.type == sf::Event::KeyPressed)
		{
			if (ev.key.code == sf::Keyboard::Num1)
			{
				changeScene(new MainScene());
			}
		}
	}
}

void SecondScene::draw()
{
	displayFps();
	displayText("Second scene", 0, 100);
	displayText("Press 1 to go to second scene", 0, 200);
}
