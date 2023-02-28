#pragma once
#include "Uno/Card.h"
#include "Lib/Test.h"

TEST(CardTest_canBePlacedRegular)
{
	using namespace card;
	constexpr Card cards_correct[]
	{
		{ CardImage::Zero, CardColor::Blue },
		{ CardImage::Zero, CardColor::Green },
		{ CardImage::One, CardColor::Green },
		{ CardImage::One, CardColor::Red },
		{ CardImage::Two, CardColor::Red },
		{ CardImage::Two, CardColor::Yellow },
		{ CardImage::PlusTwo, CardColor::Yellow },
		{ CardImage::Skip, CardColor::Yellow },
		{ CardImage::Skip, CardColor::Red },
		{ CardImage::Reverse, CardColor::Red },
		{ CardImage::Reverse, CardColor::Blue },
		{ CardImage::ChangeColor, CardColor::Blue },
		{ CardImage::ChangeColor, CardColor::Green },
		{ CardImage::PlusFourChangeColor, CardColor::Blue },
		{ CardImage::Zero, CardColor::Blue },
	};

	for (size_t i = 1; i < sizeof(cards_correct)/ sizeof(Card); i++)
	{
		EXPECTED_TRUE(canBePlacedRegular(cards_correct[i - 1], cards_correct[i]))
	}

	EXPECTED_FALSE(canBePlacedRegular({ CardImage::Zero, CardColor::Blue }, { CardImage::One, CardColor::Red }))


	return 1;
}

TEST(CardTest_canBePlacedSpecial)
{
	using namespace card;

	// Plus two.
	EXPECTED_TRUE(canBePlacedSpecial({ CardImage::PlusTwo, CardColor::Blue }, { CardImage::PlusTwo, CardColor::Blue }));
	EXPECTED_TRUE(canBePlacedSpecial({ CardImage::PlusTwo, CardColor::Blue }, { CardImage::PlusTwo, CardColor::Red }));
	EXPECTED_FALSE(canBePlacedSpecial({ CardImage::PlusTwo, CardColor::Blue }, { CardImage::PlusFourChangeColor, CardColor::Red }));
	EXPECTED_FALSE(canBePlacedSpecial({ CardImage::PlusTwo, CardColor::Blue }, { CardImage::ChangeColor, CardColor::Red }));

	// Skip.
	EXPECTED_TRUE(canBePlacedSpecial({ CardImage::Skip, CardColor::Blue }, { CardImage::Skip, CardColor::Blue }));
	EXPECTED_FALSE(canBePlacedSpecial({ CardImage::Skip, CardColor::Red }, { CardImage::Skip, CardColor::Blue }));

	// Plus four.
	EXPECTED_TRUE(canBePlacedSpecial({ CardImage::PlusFourChangeColor, CardColor::Blue }, { CardImage::PlusTwo, CardColor::Blue }));
	EXPECTED_FALSE(canBePlacedSpecial({ CardImage::PlusFourChangeColor, CardColor::Red }, { CardImage::PlusTwo, CardColor::Blue }));


	return 1;
}
