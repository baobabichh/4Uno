#pragma once
#include "Lib/Scene.h"
#include "Uno/DrawableCard.h"

using namespace card;

class CardShowScene : public Scene
{
public:
	CardShowScene();
	virtual ~CardShowScene();

	void update();
	void draw();
private:
	DrawableCard m_card;

};

