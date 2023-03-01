#include "CardShowScene.h"
#include "Lib/App.h"
#include "Lib/Text.h"
#include "SecondScene.h"


CardShowScene::CardShowScene()
{
	m_card.setCard(UnstableCard(UnstableCardImage::BackCard, UnstableCardColor::Red));
	m_card.setPosition(0, 200);
}

CardShowScene::~CardShowScene()
{
}

void CardShowScene::update()
{
	const auto& events = App::getInstance().getEvents().getContainer();

	for (const sf::Event it : events)
	{
		if (it.type == sf::Event::KeyPressed)
		{
			if (it.key.code == sf::Keyboard::Escape)
			{
				changeScene(new SecondScene());
				return;
			}

			if (it.key.code == sf::Keyboard::Right)
			{
				UnstableCard card = m_card.getCard();
				card.image = (UnstableCardImage)(((int)card.image + 1) % ((int)UnstableCardImage::EmptyColorCard + 1));
				m_card.setCard(card);
			}
			if (it.key.code == sf::Keyboard::Left)
			{
				UnstableCard card = m_card.getCard();
				if ((int)card.image - 1 < 0)
				{
					card.image = UnstableCardImage::EmptyColorCard;
				}
				else
				{
					card.image = (UnstableCardImage)((int)card.image - 1);
				}
				m_card.setCard(card);
			}

			if (it.key.code == sf::Keyboard::Up)
			{
				UnstableCard card = m_card.getCard();
				card.color = (UnstableCardColor)(((int)card.color + 1) % ((int)UnstableCardColor::NoColor + 1));
				m_card.setCard(card);
			}
			if (it.key.code == sf::Keyboard::Down)
			{
				UnstableCard card = m_card.getCard();
				if ((int)card.color - 1 < 0)
				{
					card.color = UnstableCardColor::NoColor;
				}
				else
				{
					card.color = (UnstableCardColor)((int)card.color - 1);
				}
				m_card.setCard(card);
			}

		}
	}
}

void CardShowScene::draw()
{
	displayText("Esc to go back.");
	displayText("Use arrows to change card.", 0, 50);

	std::string str = std::move(getUnstableCardStr(m_card.getCard()));
	displayText(str.c_str(), 0, 100);

	m_card.draw();
}
