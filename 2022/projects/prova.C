#include <SFML/Graphics.hpp>

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    // Create a red circle
    sf::CircleShape circle(50);
    circle.setPosition(375, 275); // Center the circle
    circle.setFillColor(sf::Color::Red);

    // Main loop
    while (window.isOpen()) {
        // Handle window events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Clear the window
        window.clear();

        // Draw the circle
        window.draw(circle);

        // Display the content of the window
        window.display();
    }

    return 0;
}
