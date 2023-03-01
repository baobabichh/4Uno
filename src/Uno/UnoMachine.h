#pragma once
#include "CardDeck.h"
#include <algorithm>

/*
	1. Take 2 cards or 4 cards.
	2. Use some card.
	3. Take card from deck.
	4. Call buff.








*/



namespace card
{
	struct Player
	{
		Player() = default;
		Player(const uint32_t id) : id(id){}

		const uint32_t id = 0;
		std::vector<StableCard> cards;
		bool isPlaying = 0;

		bool remove(StableCard card);
		bool hasCard(StableCard card) const;
	};


	class UnoMachine
	{
	public:
		UnoMachine() = default;
		UnoMachine(uint32_t numberOfPlayers);
		
		const std::vector<Player>& startGame();

		bool canUseCard(const Player& player, StableCard card); 
		void useCard(const Player& player, StableCard card);

		bool canTakePlus(const Player& player);
		void takePlus(const Player& player);

		bool canCallBluff(const Player& player);
		void callBluff(const Player& player);

		bool canTakeFromDeck(const Player& player);
		void takeFromDeck(const Player& player);

		const Player& getCurrentTurnPlayer()const;
		StableCardColor getCurrentColor()const;
		StableCard getCurrentCard()const;

		bool isEnded()const;
		const std::vector<uint32_t>& getResults()const;

	protected:
		virtual bool canBeFirstCard(StableCard card);
		virtual bool shouldPersonMakeDecision(StableCard card);

	private:
		std::vector<Player> m_players;

		CardDeck m_playingDeck;
		CardDeck m_secondDeck;
		uint32_t m_currentPlayer = 0;
		uint32_t m_prevPlayerUsedCard = 0;
		bool m_isEnded = 0;
		bool m_isReversed = 0;

		bool m_playerShouldMakeDecision = 0;

		std::vector<uint32_t> m_results;
	private:

		void updateIsEnd();
		StableCard takeOneCardFromDeck();
		void nextPlayer();
		void reverse();
		void skip();

	};
}

