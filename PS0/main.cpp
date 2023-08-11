// Hunter M Hasenfus
// Computing IV
// PS0
// Dr. Rykalova
// Jan 30, 2023
// Demonstrate ability to compile program using SFML and try out various functions.

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    // Load a sprite to display
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Texture texture;
    if (!texture.loadFromFile("sprite.jpg"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    // Create a graphical text to display

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left))
                sprite.move(-10,0);
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right))
                sprite.move(10,0);
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up))
                sprite.move(0,-10);
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down))
                sprite.move(0,10);
            if (event.type == sf::Event::MouseButtonPressed)
                sprite.rotate(90);

        }
        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(shape);
        window.draw(sprite);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}