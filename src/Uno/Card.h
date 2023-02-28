#pragma once
#include <iostream>

namespace card
{
	constexpr uint8_t CARDS_IN_DECK = 108;
	constexpr uint8_t CARDS_FOR_PLAYER = 7;


	enum class CardImage
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

	enum class CardColor : uint8_t
	{
		Red = 0,
		Blue,
		Yellow,
		Green
	};

	constexpr static const char* cardImageStr[]
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

	constexpr static const char* cardColorStr[]
	{
		"Red",
		"Blue",
		"Yellow",
		"Green"
	};

	struct Card
	{
		CardImage image;
		CardColor color;

		friend std::ostream& operator<<(std::ostream& out, const Card& card);
	};

	std::ostream& operator<<(std::ostream& out, const Card& card);

	bool isDigitCard(Card card);
	bool isActionCard(Card card);
	bool isBlackCard(Card card);

	bool isSameColor(Card prev, Card next);
	bool isSameImage(Card prev, Card next);

	bool canBePlacedRegular(Card prev, Card next);
	bool canBePlacedSpecial(Card prev, Card next);

	bool canBeContered(Card card);

}




