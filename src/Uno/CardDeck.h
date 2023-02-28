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
		void pushBack(Card card);
		Card top()const;
		void pop();
		bool isEmpty()const;
		size_t getSize()const;
		const std::vector<Card>& getContainer()const;

		void refillOtherDeck(CardDeck& other);

	private:
		std::vector<Card> m_cards;
	};

	void generateDefaultCardVector(std::vector<Card>& vector);

}

