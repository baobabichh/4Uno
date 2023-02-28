#include "Text.h"
#include "App.h"
#include "Lib/Globals.h"

sf::Text createDebugText(const char* text, uint32_t posX, uint32_t posY)
{
	sf::Text tmp;
	tmp.setFont(Globals::getFont());
	tmp.setCharacterSize(40);
	tmp.setFillColor(sf::Color::White);
	tmp.setOutlineThickness(3);
	tmp.setOutlineColor(sf::Color::Black);

	tmp.setString(text);
	tmp.setPosition(posX, posY);
	return tmp;
}

void displayFps()
{
	float fps = 1. / App::getInstance().getTimeStep();
	std::string fpsStr = std::to_string(fps);
	displayText(fpsStr.c_str());
}

void displayText(const char* str, uint32_t posX, uint32_t posY)
{
	sf::Text textDraw = createDebugText(str, posX, posY);
	App::getInstance().draw(textDraw);
}
