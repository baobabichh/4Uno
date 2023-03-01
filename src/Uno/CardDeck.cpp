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

	void CardDeck::pushBack(StableCard card)
	{
		m_cards.push_back(card);
	}

	StableCard CardDeck::top() const
	{
		if (isEmpty())
			return StableCard();
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

	const std::vector<StableCard>& CardDeck::getContainer() const
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

	void generateDefaultCardVector(std::vector< StableCard>& vector)
	{
		using namespace card;

		vector.reserve(CARDS_IN_DECK);
		for (size_t i = (int)StableCardImage::Zero; i <= (int)StableCardImage::Reverse; i++)
		{
			for (size_t c = (int)StableCardColor::Red; c <= (int)StableCardColor::Green; c++)
			{
				vector.push_back({ (StableCardImage)i, (StableCardColor)c });
				vector.push_back({ (StableCardImage)i, (StableCardColor)c });
			}
		}
		vector.push_back({ StableCardImage::ChangeColor, StableCardColor::Red });
		vector.push_back({ StableCardImage::ChangeColor, StableCardColor::Red });
		vector.push_back({ StableCardImage::ChangeColor, StableCardColor::Red });
		vector.push_back({ StableCardImage::ChangeColor, StableCardColor::Red });

		vector.push_back({ StableCardImage::PlusFourChangeColor, StableCardColor::Red });
		vector.push_back({ StableCardImage::PlusFourChangeColor, StableCardColor::Red });
		vector.push_back({ StableCardImage::PlusFourChangeColor, StableCardColor::Red });
		vector.push_back({ StableCardImage::PlusFourChangeColor, StableCardColor::Red });
	}
}
