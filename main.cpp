#include <iostream>
#include <SFML/Graphics.hpp>
#include "BlockControler.h"
#include "BigSquare.h"
#include <chrono>
#include <thread>

int main()
{
    const int windowWidth{600};
    const int windowHeight{800};
    sf::Vector2u windowSize {windowWidth, windowHeight};
    sf::RenderWindow window(sf::VideoMode(windowSize), "Tetris");
    BlockControler block;
    bool isLeftKeyPressed{false};
    bool isRightKeyPressed{false};
    bool isDownKeyPressed{false};
    BigSquare bigSquare;


    // główna pętla
    while (window.isOpen())
    {

        isLeftKeyPressed = false;
        isRightKeyPressed = false;
        isDownKeyPressed = false;

        // obsługa zdarzeń
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Left)
            {
                isLeftKeyPressed = true;
            }
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Key::Left)
            {
                //isLeftKeyPressed = false;

            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Right)
            {

                isRightKeyPressed = true;
            }
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Key::Right)
            {
                //isRightKeyPressed = false;

            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Down)
            {

                isDownKeyPressed = true;
            }
        }

        std::chrono::milliseconds delay(200);

        std::this_thread::sleep_for(delay);

        if (isLeftKeyPressed)
        {
            block.moveLeft(bigSquare);
        }
        if (isRightKeyPressed)
        {
            block.moveRight(bigSquare);
        }

        if (isDownKeyPressed)
        {
            block.updatePosition(window,bigSquare);
            block.updatePosition(window,bigSquare);
        }

        block.updatePosition(window,bigSquare);
        isRightKeyPressed = false;
        isLeftKeyPressed = false;

        // rysowanie obrazu na ekranie
        window.clear();
        for (const auto &fb : block.getCollapsedBlocks())
        {
            window.draw(fb);
        }
        for (const auto &bb : bigSquare.getShape())
        {
            window.draw(bb);
        }

        window.display();

    }

    return 0;
}
