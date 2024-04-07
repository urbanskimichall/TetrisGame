#include "BigSquare.h"

BigSquare::BigSquare()
{
    createSmallSquare();
}

void BigSquare::createSmallSquare()
{
    bigSquare.clear();
    resetPoints();
    smallSquare.setSize(sf::Vector2f(sizeOfSmallSquare, sizeOfSmallSquare));
    smallSquare.setFillColor(sf::Color::Red);
    smallSquare.setOutlineThickness(outlineThickness);
    smallSquare.setOutlineColor(sf::Color::Green);

    smallSquare.setPosition( sf::Vector2f {xUpperLeftPosition, yUpperLeftPosition});
    bigSquare.push_back(smallSquare);
    smallSquare.setPosition(sf::Vector2f {xUpperPosition, yUpperPosition});
    bigSquare.push_back(smallSquare);
    smallSquare.setPosition(sf::Vector2f {xLeftPosition, yLeftPosition});
    bigSquare.push_back(smallSquare);
    smallSquare.setPosition(sf::Vector2f {xMiddlePosition, yMiddlePosition});
    bigSquare.push_back(smallSquare);
}

const std::vector<sf::RectangleShape> &BigSquare::getShape() const
{
    return bigSquare;
}

std::vector<sf::RectangleShape> &BigSquare::getShape()
{
    return bigSquare;
}

void BigSquare::moveShapeToLeft()
{
    movePointsToLeft();
    for (auto &shape : bigSquare)
        shape.setPosition(sf::Vector2f {shape.getPosition().x - sizeOfSmallSquare, shape.getPosition().y});
}

void BigSquare::moveShapeToRight()
{
    movePointsToRight();
    for (auto &shape : bigSquare)
        shape.setPosition(sf::Vector2f {shape.getPosition().x + sizeOfSmallSquare, shape.getPosition().y});
}

void BigSquare::movePointsToRight()
{
    xMiddlePosition += sizeOfSmallSquare;
    xLeftPosition += sizeOfSmallSquare;
    xUpperPosition += sizeOfSmallSquare;
    xUpperLeftPosition += sizeOfSmallSquare;
    xLowerLeftPosition += sizeOfSmallSquare;
    xLowerPosition += sizeOfSmallSquare;
    xLowerRightPosition += sizeOfSmallSquare;
    xRightPosition += sizeOfSmallSquare;
    xUpperRightPosition += sizeOfSmallSquare;
}

void BigSquare::movePointsToLeft()
{
    xMiddlePosition -= sizeOfSmallSquare;
    xLeftPosition -= sizeOfSmallSquare;
    xUpperPosition -= sizeOfSmallSquare;
    xUpperLeftPosition -= sizeOfSmallSquare;
    xLowerLeftPosition -= sizeOfSmallSquare;
    xLowerPosition -= sizeOfSmallSquare;
    xLowerRightPosition -= sizeOfSmallSquare;
    xRightPosition -= sizeOfSmallSquare;
    xUpperRightPosition -= sizeOfSmallSquare;
}

void BigSquare::resetPoints()
{
    xLowerLeftPosition = 300.f;
    yLowerLeftPosition = 100.f;

    xLeftPosition = xLowerLeftPosition;
    yLeftPosition = yLowerLeftPosition - sizeOfSmallSquare;

    xUpperLeftPosition = xLowerLeftPosition;
    yUpperLeftPosition = yLowerLeftPosition - 2.f * sizeOfSmallSquare;

    xUpperPosition = xLowerLeftPosition + sizeOfSmallSquare;
    yUpperPosition = yLowerLeftPosition - 2.f * sizeOfSmallSquare;

    xUpperRightPosition = xLowerLeftPosition + 2.f * sizeOfSmallSquare;
    yUpperRightPosition = yLowerLeftPosition - 2.f * sizeOfSmallSquare;

    xRightPosition = xLowerLeftPosition + 2.f * sizeOfSmallSquare;
    yRightPosition = yLowerLeftPosition - sizeOfSmallSquare;

    xLowerRightPosition = xLowerLeftPosition + 2.f * sizeOfSmallSquare;
    yLowerRightPosition = yLowerLeftPosition;

    xLowerPosition = xLowerLeftPosition + sizeOfSmallSquare;
    yLowerPosition = yLowerLeftPosition;

    xMiddlePosition = xLowerLeftPosition + sizeOfSmallSquare;
    yMiddlePosition = yLowerLeftPosition - sizeOfSmallSquare;
}

void BigSquare::moveDown()
{
    yMiddlePosition += speedDown;
    yLeftPosition += speedDown;
    yUpperPosition += speedDown;
    yUpperLeftPosition += speedDown;
    yLowerLeftPosition += speedDown;
    yLowerPosition += speedDown;
    yLowerRightPosition += speedDown;
    yRightPosition += speedDown;
    yUpperRightPosition += speedDown;

    for(auto &shape : bigSquare)
    {
        shape.setPosition(sf::Vector2f {shape.getPosition().x,shape.getPosition().y+speedDown});
    }
}
