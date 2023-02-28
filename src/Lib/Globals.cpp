#include "Globals.h"
#include <ctime>
#include "Text.h"

sf::Font Globals::s_font = sf::Font();
std::mt19937 Globals::s_randomNumberGenerator = std::mt19937();

Globals::Globals()
{
	if (!s_font.loadFromFile("Resources/MontserratAlternates-Black.otf"))
		PRINT_ERROR("Failed to load font.")
		
	s_randomNumberGenerator = std::mt19937(time(0));
}

const sf::Font& Globals::getFont()
{
	return s_font;
}

int32_t Globals::rand32(int32_t min, int32_t max)
{
	std::uniform_int_distribution<int32_t> distribution(min, max);
	return distribution(s_randomNumberGenerator);
}

uint32_t Globals::randU32(uint32_t min, uint32_t max)
{
	std::uniform_int_distribution<uint32_t> distribution(min, max);
	return distribution(s_randomNumberGenerator);
}

int64_t Globals::rand64(int64_t min, int64_t max)
{
	std::uniform_int_distribution<int64_t> distribution(min, max);
	return distribution(s_randomNumberGenerator);
}

uint64_t Globals::randU64(uint64_t min, uint64_t max)
{
	std::uniform_int_distribution<uint64_t> distribution(min, max);
	return distribution(s_randomNumberGenerator);
}


