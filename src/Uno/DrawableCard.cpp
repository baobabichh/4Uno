#include "DrawableCard.h"
#include "Lib/Globals.h"
#include <vector>
#include "Lib/App.h"

namespace card
{
    card::DrawableCard::DrawableCard()
    {
        m_cardSprite.setTexture(Globals::getCardTexture());
    }

    void DrawableCard::setCard(UnstableCard card)
    {
        m_card = card;

        m_cardSprite.setTextureRect(getCardTextureRect(card));
    }

    UnstableCard DrawableCard::getCard() const
    {
        return m_card;
    }

    void DrawableCard::draw(sf::RenderStates states)
    {
        states.transform *= getTransform();

        App::getInstance().draw(m_cardSprite, states);
    }

    sf::IntRect getCardTextureRect(UnstableCard card)
    {
        auto color = card.color;
        auto image = card.image;

        constexpr int sizeX = 128, sizeY = 192, distX = 0, distY = 0;

        auto getCard = [&](int x, int y) -> sf::IntRect {
            return sf::IntRect(x * (sizeX + distX), y * (sizeY + distY), sizeX, sizeY);
        };

        if (image == UnstableCardImage::BackCard)
        {
            return getCard(3, 4);
        }

        if (image == UnstableCardImage::ChangeColor)
        {
            return getCard(1, 4);
        }

        if (image == UnstableCardImage::EmptyColorCard)
        {
            return getCard(2, 4);
        }

        if (image == UnstableCardImage::PlusFourChangeColor)
        {
            return getCard(0, 4);
        }

        if ((int)image >= (int)UnstableCardImage::Zero && (int)image <= (int)UnstableCardImage::Nine)
        {
            switch (color)
            {
            case card::UnstableCardColor::Red:
                return getCard((int)image, 0);
                break;
            case card::UnstableCardColor::Blue:
                return getCard((int)image, 1);
                break;
            case card::UnstableCardColor::Yellow:
                return getCard((int)image, 3);
                break;
            case card::UnstableCardColor::Green:
                return getCard((int)image, 2);
                break;
            default:
                return getCard(4, 4);
                break;
            }
        }

        int y = -1;

        switch (color)
        {
        case card::UnstableCardColor::Red:
            y = 0;
            break;
        case card::UnstableCardColor::Blue:
            y = 1;
            break;
        case card::UnstableCardColor::Yellow:
            y = 3;
            break;
        case card::UnstableCardColor::Green:
            y = 2;
            break;
        }
        if (y != -1)
        {
            switch (image)
            {
            case card::UnstableCardImage::Skip:
                return getCard(12, y);
                break;
            case card::UnstableCardImage::PlusTwo:
                return getCard(10, y);
                break;
            case card::UnstableCardImage::Reverse:
                return getCard(11, y);
                break;
            }
        }

        return getCard(4, 4);


        /*
        if (image == UnstableCardImage::BackCard)
            return getCard(0, 0);

        if (image == UnstableCardImage::ChangeColor)
        {
            switch (color)
            {
            case UnstableCardColor::NoColor:
                return getCard(1, 0);
            case UnstableCardColor::Yellow:
                return getCard(2, 0);
            case UnstableCardColor::Red:
                return getCard(3, 0);
            case UnstableCardColor::Blue:
                return getCard(4, 0);
            case UnstableCardColor::Green:
                return getCard(5, 0);
            }
        }

        if (image == UnstableCardImage::PlusFourChangeColor)
        {
            switch (color)
            {
            case UnstableCardColor::NoColor:
                return getCard(6, 0);
            case UnstableCardColor::Yellow:
                return getCard(7, 0);
            case UnstableCardColor::Red:
                return getCard(8, 0);
            case UnstableCardColor::Blue:
                return getCard(9, 0);
            case UnstableCardColor::Green:
                return getCard(10, 0);
            }
        }

        if (image == UnstableCardImage::EmptyColorCard)
        {
            return getCard(11, 0);
        }

        if (color == UnstableCardColor::Yellow)
        {
            if ((int)image >= (int)UnstableCardImage::One && (int)image <= (int)UnstableCardImage::Nine)
                return getCard((int)image - 1, 1);
            switch (image)
            {
            case card::UnstableCardImage::Zero:
                return getCard(9, 1);
            case card::UnstableCardImage::PlusTwo:
                return getCard(10, 1);
            case card::UnstableCardImage::Skip:
                return getCard(11, 1);
            case card::UnstableCardImage::Reverse:
                return getCard(0, 2);
            }
        }

        if (color == UnstableCardColor::Red)
        {
            if ((int)image >= (int)UnstableCardImage::One && (int)image <= (int)UnstableCardImage::Nine)
                return getCard((int)image, 2);
            switch (image)
            {
            case card::UnstableCardImage::Zero:
                return getCard(10, 2);
            case card::UnstableCardImage::PlusTwo:
                return getCard(11, 2);
            case card::UnstableCardImage::Skip:
                return getCard(0, 3);
            case card::UnstableCardImage::Reverse:
                return getCard(1, 3);
            }
        }

        if (color == UnstableCardColor::Blue)
        {
            if ((int)image >= (int)UnstableCardImage::One && (int)image <= (int)UnstableCardImage::Nine)
                return getCard((int)image + 1, 3);
            switch (image)
            {
            case card::UnstableCardImage::Zero:
                return getCard(11, 3);
            case card::UnstableCardImage::PlusTwo:
                return getCard(0, 4);
            case card::UnstableCardImage::Skip:
                return getCard(1, 4);
            case card::UnstableCardImage::Reverse:
                return getCard(2, 4);
            }
        }

        if (color == UnstableCardColor::Green)
        {
            if ((int)image >= (int)UnstableCardImage::One && (int)image <= (int)UnstableCardImage::Nine)
                return getCard((int)image + 2, 4);
            switch (image)
            {
            case card::UnstableCardImage::Zero:
                return getCard(0, 5);
            case card::UnstableCardImage::PlusTwo:
                return getCard(1, 5);
            case card::UnstableCardImage::Skip:
                return getCard(2, 5);
            case card::UnstableCardImage::Reverse:
                return getCard(3, 5);
            }
        }

        return getCard(0, 0);
        */
        
    }

}
