#pragma once
#include "Lib/Scene.h"
class SecondScene : public Scene
{
public:
	SecondScene() = default;
	virtual ~SecondScene() = default;

	virtual void update();
	virtual void draw();
	
private:

};

