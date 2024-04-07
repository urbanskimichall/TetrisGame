#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "BlockControler.h"

BlockControler::BlockControler()
{
//    block.setSize(sf::Vector2f(sizeOfBlock, sizeOfBlock));
//    block.setFillColor(sf::Color::Red);
//    block.setOutlineThickness(outlineThickness);
//    block.setOutlineColor(sf::Color::Green);
//    block.setPosition(xPosition, yPosition);
//
//
//    firstPart.setSize(sf::Vector2f(sizeOfBlock, sizeOfBlock));
//    firstPart.setFillColor(sf::Color::Red);
//    firstPart.setOutlineThickness(outlineThickness);
//    firstPart.setOutlineColor(sf::Color::Green);
//    firstPart.setPosition(xPosition, yPosition);
//
//
//    secondPart.setSize(sf::Vector2f(sizeOfBlock, sizeOfBlock));
//    secondPart.setFillColor(sf::Color::Red);
//    secondPart.setOutlineThickness(outlineThickness);
//    secondPart.setOutlineColor(sf::Color::Green);
//    secondPart.setPosition(xPosition + sizeOfBlock, yPosition);
//
//
//    thirdPart.setSize(sf::Vector2f(sizeOfBlock, sizeOfBlock));
//    thirdPart.setFillColor(sf::Color::Red);
//    thirdPart.setOutlineThickness(outlineThickness);
//    thirdPart.setOutlineColor(sf::Color::Green);
//    thirdPart.setPosition(xPosition, yPosition + sizeOfBlock);
//
//
//    fourthPart.setSize(sf::Vector2f(sizeOfBlock, sizeOfBlock));
//    fourthPart.setFillColor(sf::Color::Red);
//    fourthPart.setOutlineThickness(outlineThickness);
//    fourthPart.setOutlineColor(sf::Color::Green);
//    fourthPart.setPosition(xPosition + sizeOfBlock, yPosition + sizeOfBlock);
//
//    bigSquare.push_back(firstPart);
//    bigSquare.push_back(secondPart);
//    bigSquare.push_back(thirdPart);
//    bigSquare.push_back(fourthPart);
}

sf::RectangleShape BlockControler::getBlock() const
{
    return block;
}

void BlockControler::updatePosition(sf::RenderWindow &window, BigSquare &bigSquare)
{
    if (isBottomCollision(bigSquare))
    {
        for (const auto &shape : bigSquare.getShape())
        {
            collapsedBlocks.push_back(shape);
        }

        bigSquare.createSmallSquare();
//        std::cout << "dotkonolem ziemi:" << std::endl;
//        block.setPosition(block.getPosition().x, block.getPosition().y);
//        collapsedBlocks.push_back(block);
//        block.setPosition(xPosition, yPosition);

//        collapsedBlocks.push_back(bigSquare.at(0));
//        collapsedBlocks.push_back(bigSquare.at(1));
//        collapsedBlocks.push_back(bigSquare.at(2));
//        collapsedBlocks.push_back(bigSquare.at(3));
//
//        bigSquare.at(0).setPosition(xPosition, yPosition);
//        bigSquare.at(1).setPosition(xPosition + sizeOfBlock, yPosition);
//        bigSquare.at(2).setPosition(xPosition, yPosition + sizeOfBlock);
//        bigSquare.at(3).setPosition(xPosition + sizeOfBlock, yPosition + sizeOfBlock);
    }
    else
    {
        bigSquare.moveDown();
        //block.move(0.f, collapseSpeed);
    }
}

void BlockControler::moveLeft(BigSquare &bigSquare)
{
    //std::cout << "moveLeft -> isOtherBlockSideTouched(bigSquare): " << isOtherBlockSideTouched(bigSquare) << std::endl;
    if (!isLeftWallCollision(bigSquare) && !isOtherBlockSideTouched(bigSquare))
    {
        //std::cout << "siema" << std::endl;
        //block.setPosition(currentXposition - sizeOfBlock, block.getPosition().y);
        bigSquare.moveShapeToLeft();
    }
}


void BlockControler::moveRight(BigSquare &bigSquare)
{
    //std::cout << "moveRight -> isOtherBlockSideTouched(bigSquare): " << isOtherBlockSideTouched(bigSquare) << std::endl;
    if (!isRightWallCollision(bigSquare) && !isOtherBlockSideTouched(bigSquare))
    {
        //block.setPosition(currentXposition + sizeOfBlock, block.getPosition().y);
        bigSquare.moveShapeToRight();
    }
}

bool BlockControler::isLeftWallCollision(const BigSquare &bigSquare) const
{
    //return block.getPosition().x <= 0;
    for (const auto &shape : bigSquare.getShape())
    {
        if (shape.getPosition().x <= 0)
        {
            return true;
        }
    }
    return false;
}

bool BlockControler::isRightWallCollision(const BigSquare &bigSquare) const
{
    //return block.getPosition().x + sizeOfBlock >= 600;  //wstawić zależność od okna
    for (const auto &shape : bigSquare.getShape())
    {
        if (shape.getPosition().x + sizeOfBlock >= 600)
        {
            return true;
        }
    }
    return false;
}

bool BlockControler::isBottomCollision(const BigSquare &bigSquare) const
{
    //return block.getPosition().y + sizeOfBlock >= 800 || isOtherBlockCollision();
    for (const auto &shape : bigSquare.getShape())
    {
        if (shape.getPosition().y + sizeOfBlock >= 800 || isOtherBlockCollision(bigSquare)) //isOtherBlockCollision())
        {
            return true;
        }
    }
    return false;


}

std::vector<sf::RectangleShape> BlockControler::getCollapsedBlocks() const
{
    return collapsedBlocks;
}

bool BlockControler::isOtherBlockCollision(const BigSquare &bigSquare) const
{
    for (const auto &cb : collapsedBlocks)
    {
//        if (((collapsedBlocks.at(i).getPosition().y <= block.getPosition().y + sizeOfBlock) &&
//             (collapsedBlocks.at(i).getPosition().x == block.getPosition().x)))
        for (const auto &shape : bigSquare.getShape())
        {
            if (((cb.getPosition().y <= shape.getPosition().y + sizeOfBlock) &&
                 cb.getPosition().x == shape.getPosition().x))
            {
                return true;
            }
        }
    }
    return false;
}

std::vector<sf::RectangleShape> BlockControler::getBigBlock() const
{
    return bigSquare;
}

bool BlockControler::isOtherBlockSideTouched(const BigSquare &bigSquare) const
{
    std::cout << "NEW check isOtherBlockSideTouched" << std::endl;
    for (const auto &cb: collapsedBlocks)
    {
        for (const auto &shape: bigSquare.getShape())
        {
            std::cout << "shape.getPosition().x: " << shape.getPosition().x << " cb.getPosition().x + sizeOfBlock: "
                      << cb.getPosition().x + sizeOfBlock << std::endl;
            std::cout << "shape.getPosition().y + sizeOfBlock: " << shape.getPosition().y + sizeOfBlock
                      << " cb.getPosition().y " << cb.getPosition().y << std::endl;
            std::cout << "shape.getPosition().y " << shape.getPosition().y << " cb.getPosition().y + sizeOfBlock "
                      << cb.getPosition().y + sizeOfBlock << std::endl;

            if ((shape.getPosition().x < cb.getPosition().x + sizeOfBlock) &&
                (shape.getPosition().y + sizeOfBlock > cb.getPosition().y) &&
                (shape.getPosition().y > cb.getPosition().y + sizeOfBlock))
            {
                std::cout << "return TRUE!" << std::endl;
                return true;
            }
        }
    }
    std::cout << "return FALSE!" << std::endl;
    return false;
}





