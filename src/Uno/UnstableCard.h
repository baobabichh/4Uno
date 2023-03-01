#pragma once
#include <stdint.h>
#include "StableCard.h"

namespace card
{
	enum class UnstableCardImage : uint8_t
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
		PlusFourChangeColor,

		BackCard,
		EmptyColorCard,
	};

	enum class UnstableCardColor : uint8_t
	{
		Red = 0,
		Blue,
		Yellow,
		Green,
		NoColor,
	};

	constexpr static const char* unstableCardImageStr[]
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

		"BackCard",
		"EmptyColorCard",
	};

	constexpr static const char* unstableCardColorStr[]
	{
		"Red",
		"Blue",
		"Yellow",
		"Green",
		"NoColor",
	};

	struct UnstableCard
	{
		UnstableCard() = default;
		UnstableCard(UnstableCardImage image, UnstableCardColor color);
		UnstableCardImage image;
		UnstableCardColor color;

		friend std::ostream& operator<<(std::ostream& out, const UnstableCard& card);
	};

	std::ostream& operator<<(std::ostream& out, const UnstableCard& card);


	bool isStable(UnstableCard card);
	StableCard toStable(UnstableCard card);

	std::string getUnstableCardStr(UnstableCard card) noexcept;

}