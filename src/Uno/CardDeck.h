#pragma once
#include <vector>
#include "Card.h"

namespace card
{
	class CardDeck
	{
	public:
		CardDeck();

		void setDefault();
		void clear();
		void shuffle();
		const std::vector<Card>& getContainer()const;

	private:
		std::vector<Card> m_cards;
	};

	void generateDefaultCardVector(std::vector<Card>& vector);

}

