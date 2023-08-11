// Copyright 2023 Hunter Hasenfus
#ifndef CHECKERS_H_
#define CHECKERS_H_
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Checkers : public sf::Drawable {
 public:
        Checkers();
        ~Checkers();
        void recognizePiece(int x, int y);
 private:

        virtual void draw(sf::RenderTarget& target,
        sf::RenderStates states) const;
        char **board;

        bool turn;

        std::vector<std::string> colors = {"red", "black", "white"};
        std::string p1color;
        std::string p2color;

        sf::Texture blackPawn;
        sf::Texture redPawn;
        sf::Texture blackKing;
        sf::Texture redKing;
        sf::Texture whitePawn;
        sf::Texture whiteKing;
        sf::Texture blackBoard;
        sf::Texture redBoard;

        sf::Texture arrow;

        sf::Texture p1pawn;
        sf::Texture p1king;
        sf::Texture p2pawn;
        sf::Texture p2king;

        std::pair<std::pair<int, int>, std::pair<char, char>> selectedPiece;

        std::vector<std::pair<int, int>> p1pawns;
        std::vector<std::pair<int, int>> p1kings;

        std::vector<std::pair<int, int>> p2pawns;
        std::vector<std::pair<int, int>> p2kings;

        std::map<std::pair<int, int>, char> p1pieces;
        std::map<std::pair<int, int>, char> p2pieces;
};

#endif  // CHECKERS_H_
