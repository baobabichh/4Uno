#include "StableCard.h"

namespace card
{

	std::ostream& operator<<(std::ostream& out, const StableCard& card)
	{
		out << stableCardImageStr[(int)card.image] << " " << stableCardColorStr[(int)card.color];

		return out;
	}

	bool isDigitCard(StableCard card)
	{
		return ((int)card.image >= (int)StableCardImage::Zero) && ((int)card.image <= (int)StableCardImage::Nine);
	}

	bool isActionCard(StableCard card)
	{
		return ((int)card.image >= (int)StableCardImage::Skip) && ((int)card.image <= (int)StableCardImage::Reverse);
	}

	bool isBlackCard(StableCard card)
	{
		return ((int)card.image >= (int)StableCardImage::ChangeColor) && ((int)card.image <= (int)StableCardImage::PlusFourChangeColor);
	}

	bool isSameColor(StableCard prev, StableCard next)
	{
		return (prev.color == next.color);
	}

	bool isSameImage(StableCard prev, StableCard next)
	{
		return (prev.image == next.image);
	}

	bool canBePlacedRegular(StableCard prev, StableCard next)
	{
		if (isBlackCard(next))
			return 1;

		return (isSameColor(prev, next) || isSameImage(prev, next));
	}

	bool canBePlacedSpecial(StableCard prev, StableCard next)
	{
		// Plus two.
		if (prev.image == StableCardImage::PlusTwo && next.image == StableCardImage::PlusTwo)
			return 1;


		// Plus four.
		if (isSameColor(prev, next) && prev.image == StableCardImage::PlusFourChangeColor && next.image == StableCardImage::PlusTwo)
			return 1;

		return 0;
	}

	bool canBeContered(StableCard card)
	{
		return (StableCardImage::PlusTwo == card.image || StableCardImage::PlusFourChangeColor == card.image);
	}
}