#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cassert>

#define PRINT_ERROR(x) std::cout << "[ERROR][" << __FILE__<< ":" << __LINE__<< " " << __TIME__<< "] " << x << std::endl;

sf::Text createDebugText(const char* text = "", uint32_t posX = 0, uint32_t posY = 0);
void displayFps();
void displayText(const char* str = "", uint32_t posX = 0, uint32_t posY = 0);