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

	const std::vector<Card>& CardDeck::getContainer() const
	{
		return m_cards;
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
