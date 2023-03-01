#pragma once
#include <vector>
#include "StableCard.h"

namespace card
{
	class CardDeck
	{
	public:
		CardDeck();

		void setDefault();
		void clear();
		void shuffle();
		void pushBack(StableCard card);
		StableCard top()const;
		void pop();
		bool isEmpty()const;
		size_t getSize()const;
		const std::vector<StableCard>& getContainer()const;

		void refillOtherDeck(CardDeck& other);

	private:
		std::vector<StableCard> m_cards;
	};

	void generateDefaultCardVector(std::vector<StableCard>& vector);

}

