#pragma once
#include <iostream>

enum class CardColor : uint8_t
{
	Red = 0,
	Blue,
	Yellow,
	Green
};

enum class CardType : uint8_t
{
	Digit = 0,
	Action,
	Black
};

enum class CardActionType : uint8_t
{
	Skip = 0,
	PlusTwo,
	Reverse
};

enum class CardDigitType : uint8_t
{
	Zero = 0,
	One,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine
};

enum class CardBlackType : uint8_t
{
	ChangeColor = 0,
	PlusFourChangeColor
};

enum CardEnum : uint8_t
{
	ZeroRed = 0, ZeroBlue, ZeroYellow, ZeroGreen,
	OneRed, OneBlue, OneYellow, OneGreen,
	TwoRed, TwoBlue, TwoYellow, TwoGreen,
	ThreeRed, ThreeBlue, ThreeYellow, ThreeGreen,
	FourRed, FourBlue, FourYellow, FourGreen,
	FiveRed, FiveBlue, FiveYellow, FiveGreen,
	SixRed, SixBlue, SixYellow, SixGreen,
	SevenRed, SevenBlue, SevenYellow, SevenGreen,
	EightRed, EightBlue, EightYellow, EightGreen,
	NineRed, NineBlue, NineYellow, NineGreen,

	SkipRed, SkipBlue, SkipYellow, SkipGreen,
	PlusTwoRed, PlusTwoBlue, PlusTwoYellow, PlusTwoGreen,
	ReverseRed, ReverseBlue, ReverseYellow, ReverseGreen,

	ChangeColorRed, ChangeColorBlue, ChangeColorYellow, ChangeColorGreen,
	PlusFourChangeColorRed, PlusFourChangeColorBlue, PlusFourChangeColorYellow, PlusFourChangeColorGreen,

	COUNT
};
static_assert(((int)CardEnum::COUNT) == 60, "Number of cards should be 60.");

namespace card
{
	CardEnum createDigitCard(CardDigitType digit, CardColor color);
	CardEnum createActionCard(CardActionType type, CardColor color);
	CardEnum createBlackCard(CardBlackType type);

	bool isDigitCard(CardEnum card);
	bool isActionCard(CardEnum card);
	bool isBlackCard(CardEnum card);

	CardType getCardType(CardEnum card);
	CardColor getCardColor(CardEnum card);
	CardActionType getCardActionType(CardEnum card);
	CardDigitType getCardDigitType(CardEnum card);
	CardBlackType getCardBlackType(CardEnum card);

	bool isDigitEqual(CardEnum left, CardEnum right);
	bool isColorEqual(CardEnum left, CardEnum right);

	uint8_t getCardDigit(CardEnum card);

	bool canBePlacedAfterDigit(CardEnum prev, CardEnum next);
	bool canBePlacedAfterAction(CardEnum prev, CardEnum next);
	bool canBePlacedAfterBlack(CardEnum prev, CardEnum next);

	bool canBePlacedAfter(CardEnum prev, CardEnum next);
	
}


