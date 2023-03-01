#pragma once
#include "StableCard.h"
#include "UnstableCard.h"
#include <SFML/Graphics.hpp>
#include "Lib/MyDrawable.h"

namespace card
{
	class DrawableCard : public sf::Transformable, public MyDrawable
	{
	public:
		DrawableCard();
		void setCard(UnstableCard card);
		UnstableCard getCard()const;

		virtual void draw(sf::RenderStates states = sf::RenderStates::Default);
	private:
		sf::Sprite m_cardSprite;
		UnstableCard m_card;
	};


	sf::IntRect getCardTextureRect(UnstableCard card);
}

