#pragma once
#include "Lib/Scene.h"
#include "Uno/DrawableCard.h"

using namespace card;

class SecondScene : public Scene
{
public:
	SecondScene();
	virtual ~SecondScene() = default;

	virtual void update();
	virtual void draw();
	
private:

};

