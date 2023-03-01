#pragma once
#include "SFML/Graphics.hpp"
#include <random>

class Globals
{
public:
	Globals();
	static const sf::Font& getFont();
	static const sf::Texture& getCardTexture();

	static int32_t rand32(int32_t min, int32_t max);
	static uint32_t randU32(uint32_t min, uint32_t max);
	static int64_t rand64(int64_t min, int64_t max);
	static uint64_t randU64(uint64_t min, uint64_t max);
private:
	static sf::Font s_font;
	static sf::Texture s_cardTexture;

	static std::mt19937 s_randomNumberGenerator;
};
