#ifndef TETRIS_BIGSQUARE_H
#define TETRIS_BIGSQUARE_H

#include <vector>
#include <SFML/Graphics/RectangleShape.hpp>

class BigSquare
{
public:
    BigSquare();

    const std::vector<sf::RectangleShape> &getShape() const;

    std::vector<sf::RectangleShape> &getShape();

    void moveShapeToLeft();

    void moveShapeToRight();

    void createSmallSquare();

    void moveDown();

private:
    void movePointsToRight();

    void movePointsToLeft();

    std::vector<sf::RectangleShape> bigSquare;
    sf::RectangleShape smallSquare;
    const float sizeOfSmallSquare{30.f};
    const float outlineThickness{1.f};
    const float speedDown{20.f};
    float xLowerLeftPosition{300.f};    // the starting position of points on the perimeter
    float yLowerLeftPosition{100.f};    // of the figure, from which each subsequent one will be set clockwise

    float xLeftPosition{xLowerLeftPosition};
    float yLeftPosition{yLowerLeftPosition - sizeOfSmallSquare};

    float xUpperLeftPosition{xLowerLeftPosition};
    float yUpperLeftPosition{yLowerLeftPosition - 2.f * sizeOfSmallSquare};

    float xUpperPosition{xLowerLeftPosition + sizeOfSmallSquare};
    float yUpperPosition{yLowerLeftPosition - 2.f * sizeOfSmallSquare};

    float xUpperRightPosition{xLowerLeftPosition + 2.f * sizeOfSmallSquare};
    float yUpperRightPosition{yLowerLeftPosition - 2.f * sizeOfSmallSquare};

    float xRightPosition{xLowerLeftPosition + 2.f * sizeOfSmallSquare};
    float yRightPosition{yLowerLeftPosition - sizeOfSmallSquare};

    float xLowerRightPosition{xLowerLeftPosition + 2.f * sizeOfSmallSquare};
    float yLowerRightPosition{yLowerLeftPosition};

    float xLowerPosition{xLowerLeftPosition + sizeOfSmallSquare};
    float yLowerPosition{yLowerLeftPosition};

    float xMiddlePosition{xLowerLeftPosition + sizeOfSmallSquare};
    float yMiddlePosition{yLowerLeftPosition - sizeOfSmallSquare};

    void resetPoints();
};


#endif //TETRIS_BIGSQUARE_H
