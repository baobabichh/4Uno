#pragma once
#include "Uno/StableCard.h"
#include "Lib/Test.h"


TEST(CardTest_canBePlacedRegular)
{
	using namespace card;
	constexpr StableCard cards_correct[]
	{
		{ StableCardImage::Zero, StableCardColor::Blue },
		{ StableCardImage::Zero, StableCardColor::Green },
		{ StableCardImage::One, StableCardColor::Green },
		{ StableCardImage::One, StableCardColor::Red },
		{ StableCardImage::Two, StableCardColor::Red },
		{ StableCardImage::Two, StableCardColor::Yellow },
		{ StableCardImage::PlusTwo, StableCardColor::Yellow },
		{ StableCardImage::Skip, StableCardColor::Yellow },
		{ StableCardImage::Skip, StableCardColor::Red },
		{ StableCardImage::Reverse, StableCardColor::Red },
		{ StableCardImage::Reverse, StableCardColor::Blue },
		{ StableCardImage::ChangeColor, StableCardColor::Blue },
		{ StableCardImage::ChangeColor, StableCardColor::Green },
		{ StableCardImage::PlusFourChangeColor, StableCardColor::Blue },
		{ StableCardImage::Zero, StableCardColor::Blue },
	};

	for (size_t i = 1; i < sizeof(cards_correct)/ sizeof(StableCard); i++)
	{
		EXPECTED_TRUE(canBePlacedRegular(cards_correct[i - 1], cards_correct[i]))
	}

	EXPECTED_FALSE(canBePlacedRegular({ StableCardImage::Zero, StableCardColor::Blue }, { StableCardImage::One, StableCardColor::Red }))


	return 1;
}

TEST(CardTest_canBePlacedSpecial)
{
	using namespace card;

	// Plus two.
	EXPECTED_TRUE(canBePlacedSpecial({ StableCardImage::PlusTwo, StableCardColor::Blue }, { StableCardImage::PlusTwo, StableCardColor::Blue }));
	EXPECTED_TRUE(canBePlacedSpecial({ StableCardImage::PlusTwo, StableCardColor::Blue }, { StableCardImage::PlusTwo, StableCardColor::Red }));
	EXPECTED_FALSE(canBePlacedSpecial({ StableCardImage::PlusTwo, StableCardColor::Blue }, { StableCardImage::PlusFourChangeColor, StableCardColor::Red }));
	EXPECTED_FALSE(canBePlacedSpecial({ StableCardImage::PlusTwo, StableCardColor::Blue }, { StableCardImage::ChangeColor, StableCardColor::Red }));

	// Skip.
	EXPECTED_FALSE(canBePlacedSpecial({ StableCardImage::Skip, StableCardColor::Blue }, { StableCardImage::Skip, StableCardColor::Blue }));
	EXPECTED_FALSE(canBePlacedSpecial({ StableCardImage::Skip, StableCardColor::Red }, { StableCardImage::Skip, StableCardColor::Blue }));

	// Plus four.
	EXPECTED_TRUE(canBePlacedSpecial({ StableCardImage::PlusFourChangeColor, StableCardColor::Blue }, { StableCardImage::PlusTwo, StableCardColor::Blue }));
	EXPECTED_FALSE(canBePlacedSpecial({ StableCardImage::PlusFourChangeColor, StableCardColor::Red }, { StableCardImage::PlusTwo, StableCardColor::Blue }));


	return 1;
}
