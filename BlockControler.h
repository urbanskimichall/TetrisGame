#ifndef TETRIS_BLOCKCONTROLER_H
#define TETRIS_BLOCKCONTROLER_H


#include <SFML/System.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "BigSquare.h"

class BlockControler
{
public:
    BlockControler();

    sf::RectangleShape getBlock() const;

    std::vector<sf::RectangleShape> getBigBlock() const;

    void updatePosition(sf::RenderWindow &window, BigSquare &bigSquare);

    void moveLeft(BigSquare & bigSquare);

    void moveRight(BigSquare & bigSquare);


    std::vector<sf::RectangleShape> getCollapsedBlocks() const;




private:
    bool isLeftWallCollision(const BigSquare &bigSquare) const;

    bool isRightWallCollision(const BigSquare &bigSquare) const;

    bool isBottomCollision(const BigSquare &bigSquare) const;

    bool isOtherBlockCollision(const BigSquare & bigSquare) const;

    bool isOtherBlockSideTouched(const BigSquare & bigSquare) const;

    sf::RectangleShape block;
    std::vector<sf::RectangleShape> collapsedBlocks;
    std::vector<sf::RectangleShape> bigSquare;
    sf::RectangleShape firstPart;
    sf::RectangleShape secondPart;
    sf::RectangleShape thirdPart;
    sf::RectangleShape fourthPart;

    float sizeOfBlock{30.f};

    



};

#endif //TETRIS_BLOCKCONTROLER_H
