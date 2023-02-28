#pragma once
#include "Lib/Scene.h"
class MainScene : public Scene
{
public:
	MainScene() = default;
	virtual ~MainScene() = default;

	virtual void update();
	virtual void draw();
	
private:

};

