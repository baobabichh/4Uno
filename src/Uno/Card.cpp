#include "Card.h"

namespace card
{

	std::ostream& operator<<(std::ostream& out, const Card& card)
	{
		out << cardImageStr[(int)card.image] << " " << cardColorStr[(int)card.color];

		return out;
	}

	bool isDigitCard(Card card)
	{
		return ((int)card.image >= (int)CardImage::Zero) && ((int)card.image <= (int)CardImage::Nine);
	}

	bool isActionCard(Card card)
	{
		return ((int)card.image >= (int)CardImage::Skip) && ((int)card.image <= (int)CardImage::Reverse);
	}

	bool isBlackCard(Card card)
	{
		return ((int)card.image >= (int)CardImage::ChangeColor) && ((int)card.image <= (int)CardImage::PlusFourChangeColor);
	}

	bool isSameColor(Card prev, Card next)
	{
		return (prev.color == next.color);
	}

	bool isSameImage(Card prev, Card next)
	{
		return (prev.image == next.image);
	}

	bool canBePlacedRegular(Card prev, Card next)
	{
		if (isBlackCard(next))
			return 1;

		return (isSameColor(prev, next) || isSameImage(prev, next));
	}

	bool canBePlacedSpecial(Card prev, Card next)
	{
		// Plus two.
		if (prev.image == CardImage::PlusTwo && next.image == CardImage::PlusTwo)
			return 1;


		// Plus four.
		if (isSameColor(prev, next) && prev.image == CardImage::PlusFourChangeColor && next.image == CardImage::PlusTwo)
			return 1;

		return 0;
	}

	bool canBeContered(Card card)
	{
		return (CardImage::PlusTwo == card.image || CardImage::PlusFourChangeColor == card.image);
	}
}