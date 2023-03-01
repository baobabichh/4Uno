#include "SecondScene.h"
#include "Lib/Text.h"
#include "Lib/App.h"
#include "MainScene.h"
#include "CardShowScene.h"

SecondScene::SecondScene()
{

}

void SecondScene::update()
{
	for (const auto ev : App::getInstance().getEvents().getContainer())
	{
		if (ev.type == sf::Event::KeyPressed)
		{
			if (ev.key.code == sf::Keyboard::Num1)
			{
				changeScene(new CardShowScene());
				return;
			}
		}
	}
}

void SecondScene::draw()
{
	displayFps();
	displayText("Show scene", 0, 100);
	displayText("Press 1 to go card show scene", 0, 200);
}
