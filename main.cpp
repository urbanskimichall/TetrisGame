#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    const sf::Vector2u x {800, 600};
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Hello, World!" << std::endl;
    // Utwórz obiekt okna o wymiarach 800x600
    sf::RenderWindow window(sf::VideoMode(x), "SFML Window");

    // Główna pętla programu
    while (window.isOpen()) {
        // Obsługa zdarzeń
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Wyczyszczenie okna (ustawienie koloru na biały)
        window.clear(sf::Color::White);

        // Tutaj można dodać kod rysowania i inne operacje

        // Wyświetlenie zawartości okna
        window.display();
    }

    return 0;
}
