#include "Card.h"

CardEnum card::createDigitCard(CardDigitType digit, CardColor color)
{
	const uint8_t d = (int)digit;
	const uint8_t c = (int)color;
	const uint8_t res = d * 4 + c;
	return (CardEnum)res;
}

CardEnum card::createActionCard(CardActionType type, CardColor color)
{
	const uint8_t t = (int)type;
	const uint8_t c = (int)color;
	const uint8_t res = t * 4 + c;
	return (CardEnum)res;
}

CardEnum card::createBlackCard(CardBlackType type)
{
	if (CardBlackType::ChangeColor == type)
		return CardEnum::ChangeColorBlack;
	return CardEnum::PlusFourChangeColorBlack;
}

bool card::isDigitCard(CardEnum card)
{
	return (((int)card >= CardEnum::ZeroRed) && ((int)card <= CardEnum::NineGreen));
}

bool card::isActionCard(CardEnum card)
{
	return (((int)card >= CardEnum::SkipRed) && ((int)card <= CardEnum::ReverseGreen));
}

bool card::isBlackCard(CardEnum card)
{
	return (((int)card >= CardEnum::ChangeColorBlack) && ((int)card <= CardEnum::PlusFourChangeColorBlack));
}

CardType card::getCardType(CardEnum card)
{
	if (isDigitCard(card))
		return CardType::Digit;
	if (isActionCard(card))
		return CardType::Action;
	if (isBlackCard(card))
		return CardType::Black;
}

CardColor card::getCardColor(CardEnum card)
{
	return(CardColor)(((int)card) % 4);
}

CardActionType card::getCardActionType(CardEnum card)
{
	if (((int)card >= CardEnum::SkipRed) && ((int)card <= CardEnum::SkipGreen))
		return CardActionType::Skip;

	if (((int)card >= CardEnum::PlusTwoRed) && ((int)card <= CardEnum::PlusTwoGreen))
		return CardActionType::PlusTwo;

	if (((int)card >= CardEnum::ReverseRed) && ((int)card <= CardEnum::ReverseGreen))
		return CardActionType::Reverse;
}

CardDigitType card::getCardDigitType(CardEnum card)
{
	return CardDigitType((int)(card) / 4);
}

CardBlackType card::getCardBlackType(CardEnum card)
{
	if (CardEnum::ChangeColorBlack == card)
		return CardBlackType::ChangeColor;
	return CardBlackType::PlusFourChangeColor;
}

bool card::isDigitEqual(CardEnum left, CardEnum right)
{
	return getCardDigit(left) == getCardDigit(right);
}

bool card::isColorEqual(CardEnum left, CardEnum right)
{
	return getCardColor(left) == getCardColor(right);
}

uint8_t card::getCardDigit(CardEnum card)
{
	return (uint8_t)getCardDigitType(card);
}

#include "Lib/Text.h"

bool card::canBePlacedAfterDigit(CardEnum prev, CardEnum next)
{
	assert(isDigitCard(prev) && "This function is only for digit cards.");

	const CardType prevType = getCardType(prev);
	const CardType nextType = getCardType(next);
	const CardActionType prevActionType = getCardActionType(prev);
	const CardActionType nextActionType = getCardActionType(next);
	const CardColor prevColor = getCardColor(prev);
	const CardColor nextColor = getCardColor(next);
	const CardDigitType prevDigit = getCardDigitType(prev);
	const CardDigitType nextDigit = getCardDigitType(next);

	if (nextType == CardType::Digit)
	{
		if (prevDigit == nextDigit)
			return 1;
		else if (prevColor == nextColor)
			return 1;
		return 0;
	}
	else if (nextType == CardType::Black)
	{
		return 1;
	}
	else if (nextType == CardType::Action)
	{
		if (prevColor == nextColor)
			return 1;
		return 0;
	}

	assert(0 && "Should not be here.");
}

bool card::canBePlacedAfterAction(CardEnum prev, CardEnum next)
{
	assert(isActionCard(prev) && "This function is only for digit cards.");

	const CardType prevType = getCardType(prev);
	const CardType nextType = getCardType(next);
	const CardActionType prevActionType = getCardActionType(prev);
	const CardActionType nextActionType = getCardActionType(next);
	const CardColor prevColor = getCardColor(prev);
	const CardColor nextColor = getCardColor(next);
	const CardDigitType prevDigit = getCardDigitType(prev);
	const CardDigitType nextDigit = getCardDigitType(next);

	if (nextType == CardType::Action)
	{
		if (prevActionType == nextActionType)
			return 1;
		else if (prevColor == nextColor)
			return 1;
		return 0;
	}
	else if (nextType == CardType::Black)
	{
		if (prevActionType == CardActionType::PlusTwo)
			return 0;
	}
	else if (nextType == CardType::Digit)
	{
		if (prevColor == nextColor)
			return 1;
		return 0;
	}

	assert(0 && "Should not be here.");

}

bool card::canBePlacedAfterBlack(CardEnum prev, CardEnum next)
{
	assert(isActionCard(prev) && "This function is only for digit cards.");

	const CardType prevType = getCardType(prev);
	const CardType nextType = getCardType(next);
	const CardActionType prevActionType = getCardActionType(prev);
	const CardActionType nextActionType = getCardActionType(next);
	const CardColor prevColor = getCardColor(prev);
	const CardColor nextColor = getCardColor(next);
	const CardDigitType prevDigit = getCardDigitType(prev);
	const CardDigitType nextDigit = getCardDigitType(next);

	if (nextType == CardType::Action)
	{
		if (prevActionType == nextActionType)
			return 1;
		else if (prevColor == nextColor)
			return 1;
		return 0;
	}
	else if (nextType == CardType::Black)
	{
		if (prevActionType == CardActionType::PlusTwo)
			return 0;
	}
	else if (nextType == CardType::Digit)
	{
		if (prevColor == nextColor)
			return 1;
		return 0;
	}

	assert(0 && "Should not be here.");
}

bool card::canBePlacedAfter(CardEnum prev, CardEnum next)
{
	const CardType prevType = getCardType(prev);
	const CardType nextType = getCardType(next);
	const CardActionType prevActionType = getCardActionType(prev);
	const CardActionType nextActionType = getCardActionType(next);
	const CardColor prevColor = getCardColor(prev);
	const CardColor nextColor = getCardColor(next);
	const CardDigitType prevDigit = getCardDigitType(prev);
	const CardDigitType nextDigit = getCardDigitType(next);

	if (CardType::Action == nextType)
	{
		if (CardType::Action == prevType)
		{
			if (prevActionType == nextActionType)
				return 1;
			else if (prevColor == nextColor)
				return 1;
			else
				return 0;
		}
		else if (CardType::Digit == prevType)
		{
			if (prevColor == nextColor)
				return 1;
			else
				return 0;
		}
		else
		{
			return 0;
		}
	}
	else if (CardType::Black == nextType)
	{
		return 1;
	}
	else if (CardType::Digit == nextType)
	{
		if (CardType::Action == prevType)
		{
			if (prevActionType == nextActionType)
				return 1;
			else if (prevColor == nextColor)
				return 1;
			else
				return 0;
		}
		else if (CardType::Digit == prevType)
		{
			if (prevColor == nextColor)
				return 1;
			else if (prevDigit == nextDigit)
				return 1;
			else
				return 0;
		}
		else
		{
			return 0;
		}
	}
}

bool card::canBePlacedAfterBlack(CardEnum prev, CardColor newColor, CardEnum next)
{
	const CardType prevType = getCardType(prev);
	const CardType nextType = getCardType(next);
	const CardActionType prevActionType = getCardActionType(prev);
	const CardActionType nextActionType = getCardActionType(next);
	const CardColor prevColor = getCardColor(prev);
	const CardColor nextColor = getCardColor(next);
	const CardDigitType prevDigit = getCardDigitType(prev);
	const CardDigitType nextDigit = getCardDigitType(next);

	if (CardEnum::ChangeColorBlack == prev)
	{

	}
}
