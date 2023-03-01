#include "UnoMachine.h"
#include <assert.h>

namespace card
{
	UnoMachine::UnoMachine(uint32_t numberOfPlayers)
	{
		assert((numberOfPlayers * CARDS_FOR_PLAYER <= CARDS_IN_DECK) && "Number of players is too big.");

		m_players.reserve(numberOfPlayers);
		for (size_t i = 0; i < numberOfPlayers; i++)
		{
			m_players.emplace_back(i);
		}
	}
	const std::vector<Player>& UnoMachine::startGame()
	{
		m_isEnded = 0;

		for (size_t i = 0; i < m_players.size(); i++)
		{
			m_players[i].isPlaying = 1;
		}

		m_playingDeck.setDefault();
		m_playingDeck.shuffle();
		
		for (size_t i = 0; i < m_players.size(); i++)
		{
			for (size_t j = 0; j < CARDS_FOR_PLAYER; j++)
			{
				m_players[i].cards.push_back(m_playingDeck.top());
				m_playingDeck.pop();
			}
		}

		while (!canBeFirstCard(m_playingDeck.top()))
		{
			m_playingDeck.shuffle();
		}

		if (shouldPersonMakeDecision(m_playingDeck.top()))
		{
			m_playerShouldMakeDecision = 1;
		}

		m_playingDeck.refillOtherDeck(m_secondDeck);
		m_secondDeck.shuffle();

		return m_players;
	}
	bool UnoMachine::canUseCard(const Player& p, StableCard card)
	{
		auto& player = m_players[p.id];

		if (m_isEnded || !player.hasCard(card) || m_currentPlayer != player.id || canTakePlus(player))
			return 0;

		if (m_playerShouldMakeDecision)
		{
			if (canBePlacedSpecial(card, m_playingDeck.top()))
			{
				return 1;
			}
			return 0;
		}

		if (!m_playerShouldMakeDecision)
		{
			if (canBePlacedRegular(card, m_playingDeck.top()))
			{
				return 1;
			}
			return 0;
		}

	}
	void UnoMachine::useCard(const Player& p, StableCard card)
	{
		auto& player = m_players[p.id];

		if (!canUseCard(player, card))
			return;

		m_prevPlayerUsedCard = m_currentPlayer;
		m_currentPlayer = player.id;

		m_playingDeck.pushBack(card);
		if (canBeContered(card))
		{
			m_playerShouldMakeDecision = 1;
		}
		else
		{
			m_playerShouldMakeDecision = 0;
		}

		if (StableCardImage::Reverse == card.image)
		{
			reverse();
		}
		else if (StableCardImage::Skip == card.image)
		{
			nextPlayer();
		}

		nextPlayer();

		player.remove(card);

		if (player.cards.size() == 0)
		{
			m_results.push_back(player.id);
		}
		if (m_results.size() == m_players.size() - 1)
			m_isEnded = 1;

	}
	bool UnoMachine::canTakePlus(const Player& player)
	{
		if (m_isEnded || m_currentPlayer != player.id || !m_playerShouldMakeDecision)
			return 0;

		if (m_playingDeck.top().image == StableCardImage::PlusTwo || m_playingDeck.top().image == StableCardImage::PlusFourChangeColor)
		{
			return 1;
		}

		return 0;
	}
	void UnoMachine::takePlus(const Player& player)
	{
		if (!canTakePlus(player))
			return;

		m_playerShouldMakeDecision = 0;

		if (m_playingDeck.top().image == StableCardImage::PlusTwo)
		{
			m_players[player.id].cards.push_back(takeOneCardFromDeck());
			m_players[player.id].cards.push_back(takeOneCardFromDeck());
		}
		else if (m_playingDeck.top().image == StableCardImage::PlusFourChangeColor)
		{
			m_players[player.id].cards.push_back(takeOneCardFromDeck());
			m_players[player.id].cards.push_back(takeOneCardFromDeck());
			m_players[player.id].cards.push_back(takeOneCardFromDeck());
			m_players[player.id].cards.push_back(takeOneCardFromDeck());
		}

		nextPlayer();
	}
	bool UnoMachine::canCallBluff(const Player& player)
	{
		if (m_isEnded || m_currentPlayer != player.id || !canTakePlus(player))
			return 0;

		if (m_playerShouldMakeDecision)
		{
			if (m_playingDeck.top().image == StableCardImage::PlusFourChangeColor)
			{
				return 1;
			}
		}

		return 0;
	}
	void UnoMachine::callBluff(const Player& player)
	{
		if (!canCallBluff(player))
			return;

		m_playerShouldMakeDecision = 0;

		bool successBluff = 0;

		const auto& deckCards = m_playingDeck.getContainer();
		const StableCard prevprevCard = deckCards[deckCards.size() - 2];
		for (const auto it : (m_players[m_prevPlayerUsedCard].cards))
		{
			if (prevprevCard.color == it.color)
			{
				successBluff = 1;
				break;
			}
		}

		// Give 6 cards.
		if (successBluff)
		{
			m_players[m_prevPlayerUsedCard].cards.push_back(takeOneCardFromDeck());
			m_players[m_prevPlayerUsedCard].cards.push_back(takeOneCardFromDeck());
			m_players[m_prevPlayerUsedCard].cards.push_back(takeOneCardFromDeck());
			m_players[m_prevPlayerUsedCard].cards.push_back(takeOneCardFromDeck());
			m_players[m_prevPlayerUsedCard].cards.push_back(takeOneCardFromDeck());
			m_players[m_prevPlayerUsedCard].cards.push_back(takeOneCardFromDeck());
		}

		nextPlayer();		
	}

	bool UnoMachine::canTakeFromDeck(const Player& player)
	{
		if (m_isEnded || m_currentPlayer != player.id || canTakePlus(player))
			return 0;

		return 1;
	}

	void UnoMachine::takeFromDeck(const Player& player)
	{
		if (!canTakeFromDeck(player))
			return;

		m_players[player.id].cards.push_back(takeOneCardFromDeck());

		nextPlayer();
	}

	const Player& UnoMachine::getCurrentTurnPlayer() const
	{
		return m_players[m_currentPlayer];
	}
	StableCardColor UnoMachine::getCurrentColor() const
	{
		return m_playingDeck.top().color;
	}
	StableCard UnoMachine::getCurrentCard() const
	{
		return m_playingDeck.top();
	}
	bool UnoMachine::isEnded() const
	{
		return m_isEnded;
	}

	const std::vector<uint32_t>& UnoMachine::getResults() const
	{
		return m_results;
	}

	void UnoMachine::updateIsEnd()
	{
		uint32_t numberOfPlayersWithCards =
			std::count_if(std::begin(m_players), std::end(m_players), [](const Player& player) -> bool { return player.cards.size(); });
		if (numberOfPlayersWithCards == 1)
			m_isEnded = 1;
		else
			m_isEnded = 0;
	}

	StableCard UnoMachine::takeOneCardFromDeck()
	{
		if (m_secondDeck.isEmpty())
		{
			m_playingDeck.refillOtherDeck(m_secondDeck);
		}

		auto res = m_secondDeck.top();
		m_secondDeck.pop();
		return res;
	}
	void UnoMachine::nextPlayer()
	{
		if (m_isReversed)
		{
			if (m_currentPlayer == 0)
			{
				m_currentPlayer = m_players.size() - 1;
			}
			else
			{
				m_currentPlayer--;
				while (m_players[m_currentPlayer].cards.empty())
				{
					if (m_currentPlayer == 0)
					{
						m_currentPlayer = m_players.size() - 1;
					}
					else
					{
						m_currentPlayer--;
					}
				}
				
			}
		}
		else
		{
			m_currentPlayer = (m_currentPlayer + 1) % m_players.size();
			while (m_players[m_currentPlayer].cards.empty())
			{
				m_currentPlayer = (m_currentPlayer + 1) % m_players.size();
			}
		}
	}
	void UnoMachine::reverse()
	{
		m_isReversed = !m_isReversed;
	}

	void UnoMachine::skip()
	{
		nextPlayer();
	}

	bool UnoMachine::canBeFirstCard(StableCard card)
	{
		return !isBlackCard(card);
	}
	bool UnoMachine::shouldPersonMakeDecision(StableCard card)
	{
		return (StableCardImage::PlusTwo == card.image || StableCardImage::PlusFourChangeColor == card.image);
	}
	bool Player::hasCard(StableCard card)const
	{
		auto it = std::find_if(std::begin(cards), std::end(cards), [&](StableCard curr) {return curr.image == card.image && curr.color == card.color; });
		return (it != std::end(cards));
	}
	bool Player::remove(StableCard card)
	{
		auto it = std::find_if(std::begin(cards), std::end(cards), [&](StableCard curr) {return curr.image == card.image && curr.color == card.color; });
		if (it == std::end(cards))
			return 0;
		cards.erase(it);
		return 1;
	}
}