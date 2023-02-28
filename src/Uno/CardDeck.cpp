#include "CardDeck.h"
#include <algorithm>

namespace card
{

	CardDeck::CardDeck()
	{
		m_cards.reserve(CARDS_IN_DECK);
	}

	void CardDeck::setDefault()
	{
		generateDefaultCardVector(m_cards);
	}

	void CardDeck::clear()
	{
		m_cards.clear();
	}

	void CardDeck::shuffle()
	{
		std::random_shuffle(std::begin(m_cards), std::end(m_cards));
	}

	void CardDeck::pushBack(Card card)
	{
		m_cards.push_back(card);
	}

	Card CardDeck::top() const
	{
		if (isEmpty())
			return Card();
		return m_cards.back();
	}

	void CardDeck::pop()
	{
		m_cards.pop_back();
	}

	bool CardDeck::isEmpty() const
	{
		return m_cards.empty();
	}

	size_t CardDeck::getSize() const
	{
		return m_cards.size();
	}

	const std::vector<Card>& CardDeck::getContainer() const
	{
		return m_cards;
	}

	void CardDeck::refillOtherDeck(CardDeck& other)
	{
		other.clear();
		while (getSize() > 1)
		{
			other.pushBack(top());
			pop();
		}

		other.shuffle();
	}

	void generateDefaultCardVector(std::vector< Card>& vector)
	{
		using namespace card;

		vector.reserve(CARDS_IN_DECK);
		for (size_t i = (int)CardImage::Zero; i <= (int)CardImage::Reverse; i++)
		{
			for (size_t c = (int)CardColor::Red; c <= (int)CardColor::Green; c++)
			{
				vector.push_back({ (CardImage)i, (CardColor)c });
				vector.push_back({ (CardImage)i, (CardColor)c });
			}
		}
		vector.push_back({ CardImage::ChangeColor, CardColor::Red });
		vector.push_back({ CardImage::ChangeColor, CardColor::Red });
		vector.push_back({ CardImage::ChangeColor, CardColor::Red });
		vector.push_back({ CardImage::ChangeColor, CardColor::Red });

		vector.push_back({ CardImage::PlusFourChangeColor, CardColor::Red });
		vector.push_back({ CardImage::PlusFourChangeColor, CardColor::Red });
		vector.push_back({ CardImage::PlusFourChangeColor, CardColor::Red });
		vector.push_back({ CardImage::PlusFourChangeColor, CardColor::Red });
	}
}
