#pragma once
#include "Lib/Test.h"
#include "Uno/UnoMachine.h"
#include "Lib/Debug.h"

TEST(UnoMachineTest)
{
	return 1;

	using namespace card;

	UnoMachine uno(4);
	const std::vector<Player>& players = uno.startGame();

	while (!uno.isEnded())
	{
		auto& currentPlayer = uno.getCurrentTurnPlayer();
		auto currentCard = uno.getCurrentCard();

		std::cout << "\n";
		std::cout << "Current card: " << currentCard << "\n";
		std::cout << "Current player: " << currentPlayer.id << "\n";
		for (const auto& it : players)
		{
			std::cout << "Player " << it.id << " : ";
			for (const auto card : it.cards)
			{
				std::cout << card << ", ";
			}
			std::cout << "\n";
		}


		if (uno.canCallBluff(currentPlayer))
		{
			std::cout << "Player " << currentPlayer.id << " calling buff.\n";
			uno.callBluff(currentPlayer);
			continue;
		}

		if (uno.canTakePlus(currentPlayer))
		{
			std::cout << "Player " << currentPlayer.id << " take.\n";
			uno.takePlus(currentPlayer);
			continue;
		}

		bool flag = 0;
		for (const auto card : currentPlayer.cards)
		{
			if (uno.canUseCard(currentPlayer, card))
			{
				std::cout << "Player " << currentPlayer.id << " use card " << card << ".\n";
				uno.useCard(currentPlayer, card);
				flag = 1;
				break;
			}
		}

		if (uno.canTakeFromDeck(currentPlayer) && !flag)
		{
			std::cout << "Player " << currentPlayer.id << " take from deck.\n";
			uno.takeFromDeck(currentPlayer);
			continue;
		}
	}

	std::cout << "Winers: \n";
	for (const auto player : uno.getResults())
	{
		std::cout << "Player " << player << "\n";
	}

	return 0;

}