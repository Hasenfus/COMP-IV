// Copyright 2023 Hunter Hasenfus
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Checkers.h"

int main(int arg, char* argc[]) {
    bool replay = false;
    do {
        Checkers s;

        sf::RenderWindow window(sf::VideoMode(8 * 64, 8 * 64), argc[0]);
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::MouseButtonPressed
                 && sf::Mouse::Left == event.mouseButton.button) {
                    // sf::Vector2i localPosition =
                    //  sf::Mouse::getPosition(window);
                    // s.recognizePiece(localPosition.x, localPosition.y);
                    s.recognizePiece(event.mouseButton.x, event.mouseButton.y);
                    // cout << event.mouseButton.x << "," <<
                    // event.mouseButton.y << endl;
                }}
            window.clear();
            window.draw(s);
            window.display();
        }
        std::cout << "Would you like to play again? (y/n)";
        std::cin >> replay;
        if (replay == 'y')
            replay = true;
        else
            replay = false;
    } while (replay);

    return 0;
}
