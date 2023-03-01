#include "UnstableCard.h"

namespace card
{
	std::ostream& card::operator<<(std::ostream& out, const UnstableCard& card)
	{
		out << unstableCardImageStr[(int)card.image] << " " << unstableCardColorStr[(int)card.color];

		return out;
	}

	bool card::isStable(UnstableCard card)
	{
		return !(UnstableCardColor::NoColor == card.color ||
			UnstableCardImage::BackCard == card.image ||
			UnstableCardImage::EmptyColorCard == card.image);
	}

	StableCard card::toStable(UnstableCard card)
	{
		StableCard res;
		res.color = (StableCardColor)card.color;
		res.image = (StableCardImage)card.image;
		return res;
	}
	std::string getUnstableCardStr(UnstableCard card) noexcept
	{
		std::string res = std::string(unstableCardImageStr[(int)card.image]);
		res += +" ";
		res += unstableCardColorStr[(int)card.color];
		return std::move(res);
	}
	UnstableCard::UnstableCard(UnstableCardImage image, UnstableCardColor color)
		: image(image), color(color)
	{
	}
}


