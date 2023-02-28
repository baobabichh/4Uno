#pragma once
#include <iostream>

namespace card
{
	constexpr uint8_t CARDS_IN_DECK = 108;

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

	struct Card
	{
		CardImage image;
		CardColor color;
	};

	bool isDigitCard(Card card);
	bool isActionCard(Card card);
	bool isBlackCard(Card card);

	bool isSameColor(Card prev, Card next);
	bool isSameImage(Card prev, Card next);

	bool canBePlacedRegular(Card prev, Card next);
	bool canBePlacedSpecial(Card prev, Card next);





}




