#pragma once
#include <iostream>

namespace card
{
	constexpr uint8_t CARDS_IN_DECK = 108;
	constexpr uint8_t CARDS_FOR_PLAYER = 7;


	enum class StableCardImage : uint8_t
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
		Nine, 

		Skip,
		PlusTwo,
		Reverse, 

		ChangeColor,
		PlusFourChangeColor
	};

	enum class StableCardColor : uint8_t
	{
		Red = 0,
		Blue,
		Yellow,
		Green
	};

	constexpr static const char* stableCardImageStr[]
	{
		"Zero",
		"One",
		"Two",
		"Three",
		"Four",
		"Five",
		"Six",
		"Seven",
		"Eight",
		"Nine",

		"Skip",
		"PlusTwo",
		"Reverse",

		"ChangeColor",
		"PlusFourChangeColor",
	};

	constexpr static const char* stableCardColorStr[]
	{
		"Red",
		"Blue",
		"Yellow",
		"Green"
	};

	struct StableCard
	{
		StableCardImage image;
		StableCardColor color;

		friend std::ostream& operator<<(std::ostream& out, const StableCard& card);
	};

	std::ostream& operator<<(std::ostream& out, const StableCard& card);

	bool isDigitCard(StableCard card);
	bool isActionCard(StableCard card);
	bool isBlackCard(StableCard card);

	bool isSameColor(StableCard prev, StableCard next);
	bool isSameImage(StableCard prev, StableCard next);

	bool canBePlacedRegular(StableCard prev, StableCard next);
	bool canBePlacedSpecial(StableCard prev, StableCard next);

	bool canBeContered(StableCard card);

}




