// Copyright 2023 Hunter Hasenfus
#include "Checkers.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <algorithm>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


void Checkers::recognizePiece(int x, int y) {
    double n, m;
    if (x > 36 && x < 36 + 55 * 8 && y > 36 && y < 36 + 55 * 8) {
        m = (x-36) / 55;
        n = (y-36) / 55;
        if (turn) {
            auto Piece = find_if(p1pieces.begin(), p1pieces.end(),
             [n, m](std::pair<std::pair<int, int>
            , char> x){return x.first.first == n && x.first.second == m;});
            if (Piece != p1pieces.end())
                selectedPiece = make_pair(Piece->first,
                 std::make_pair(Piece->second, '1'));
            else
                selectedPiece = std::make_pair(std::make_pair(-1, -1),
                 std::make_pair('0', '0'));
        } else {
            auto Piece = find_if(p2pieces.begin(), p2pieces.end(),
             [n, m](std::pair<std::pair<int, int>
            , char> x){return x.first.first == n && x.first.second == m;});
            if (Piece != p2pieces.end())
                selectedPiece = make_pair(Piece->first,
                 std::make_pair(Piece->second, '2'));
            else
                selectedPiece = std::make_pair(std::make_pair(-1, -1),
                 std::make_pair('0', '0'));
        }} else {
        selectedPiece = std::make_pair(std::make_pair(-1, -1),
         std::make_pair('0', '0'));
    }
    // cout << n << "," << m << endl;
    // cout << selectedPiece.first.first << "," <<
    // selectedPiece.first.second << " "
    //  << selectedPiece.second.first << " " <<
    // selectedPiece.second.second << endl;
}

Checkers::~Checkers() {
    for (int i = 0; i < 8; i++) {
        delete[] board[i];
    }
    delete[] board;
}


Checkers::Checkers() {
    blackPawn.loadFromFile("checkers/blackpawn.png");
    redPawn.loadFromFile("checkers/redpawn.png");
    blackKing.loadFromFile("checkers/blackking.png");
    redKing.loadFromFile("checkers/redking.png");
    whitePawn.loadFromFile("checkers/whitepawn.png");
    whiteKing.loadFromFile("checkers/whiteking.png");
    arrow.loadFromFile("checkers/download.png");


    turn = true;
    selectedPiece = std::make_pair(std::make_pair(-1, -1),
     std::make_pair('0', '0'));

    std::vector<std::string>::iterator y;
    std::cout << "Choose a color for player 1 (red, black, or white)";
    do {
        std::cin >> p1color;
        y = find_if(colors.begin(), colors.end(), [this](std::string x)
        {return x == this->p1color;});
    } while (y == colors.end());

    if (p1color == "black") {
        p1pawn = blackPawn;
        p1king = blackKing;
    } else { if (p1color == "red") {
        p1pawn = redPawn;
        p1king = redKing;
    } else {if (p1color == "white") {
        p1pawn = whitePawn;
        p1king = whiteKing;
    }}}
    colors.erase(y);

    std::cout << "Choose a color for player 2 (" << colors[0] << " or "
     << colors[1] << ")";
    do {
        std::cin >> p2color;
    } while (find_if(colors.begin(), colors.end(), [this](std::string x)
    {return x == this->p2color;}) == colors.end());

    if (p2color == "black") {
        p2pawn = blackPawn;
        p2king = blackKing;
    } else {if (p2color == "red") {
        p2pawn = redPawn;
        p2king = redKing;
    } else {if (p2color == "white") {
        p2pawn = whitePawn;
        p2king = whiteKing;
    }}}

    board = new char*[8];
    for (int i = 0; i < 8; i++) {
        board[i] = new char[8];
        for (int j = 0; j < 8; j ++) {
            if (i % 2) {
                if (j % 2) {
                    board[i][j] = 'r';
                } else {
                    board[i][j] = 'b';
                    if (i < 3) {
                        p1pieces.insert(std::make_pair(
                            std::make_pair(i, j), 'p'));
                    } else if (i > 4) {
                        p2pieces.insert(std::make_pair(
                            std::make_pair(i, j), 'p'));
                    }}} else {
                if (j % 2) {
                    board[i][j] = 'b';
                    if (i < 3) {
                        p1pieces.insert(std::make_pair(
                            std::make_pair(i, j), 'p'));
                    } else {if (i > 4) {
                        p2pieces.insert(std::make_pair(
                            std::make_pair(i, j), 'p'));
                    }}} else {
                    board[i][j] = 'r';
                }}}}
    // cout << "p1pawns:" << endl;
    // for(auto x: p1pieces) {
    //     std::cout << x.first.first << " " << x.first.second << " - ";
    // }
    // cout << endl << "p2pawns:" << endl;
    // for(auto x: p2pieces) {
    //     std::cout << x.first.first << " " << x.first.second << " - ";
    // }
}

void Checkers::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (int i = 0; i < 3; i ++) {
        sf::RectangleShape border(sf::Vector2f(8 * (64 - i * 4),
         8 * (64 - i * 4)));
        border.setPosition(i * 16, i * 16);
        border.setFillColor(sf::Color(175 + i * 25, 175 + i * 25,
         100 + i * 25));
        border.setOutlineColor(sf::Color::Black);
        border.setOutlineThickness(0.5f);
        target.draw(border);
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            sf::RectangleShape rect(sf::Vector2f(55, 55));
            rect.setPosition(36 + i * 55, 36 + j * 55);

            rect.setOutlineColor(sf::Color::Black);
            rect.setOutlineThickness(0.1f);
            sf::Sprite sprite;
            switch (board[i][j]) {
                case 'b':
                    rect.setFillColor(sf::Color::Black);
                    break;
                case 'r':
                    rect.setFillColor(sf::Color::Red);
                    break;
            }
            target.draw(rect);
        }
    }


    for (auto x : p1pieces) {
        sf::Sprite sprite;
        if (x.second == 'p')
            sprite.setTexture(p1pawn);
        else
            sprite.setTexture(p1king);
        sprite.scale(55.0/p1pawn.getSize().x, 55.0/p1pawn.getSize().y);
        sprite.setPosition(36 + x.first.second * 55, 36 + x.first.first * 55);
        target.draw(sprite);
    }

    for (auto x : p2pieces) {
        sf::Sprite sprite;
        if (x.second == 'p')
            sprite.setTexture(p2pawn);
        else
            sprite.setTexture(p2king);
        sprite.scale(55.0/p2pawn.getSize().x, 55.0/p2pawn.getSize().y);
        sprite.setPosition(36 + x.first.second * 55, 36 + x.first.first * 55);
        target.draw(sprite);
    }

    sf::Sprite sprite;
    if (selectedPiece.second.second != '0') {
        if (selectedPiece.second.second == '1') {
            if (selectedPiece.second.first == 'p')
                sprite.setTexture(p1pawn);
            else
                sprite.setTexture(p1king);
        } else { if (selectedPiece.second.second == '2') {
            if (selectedPiece.second.first == 'p')
                sprite.setTexture(p2pawn);
            else
                sprite.setTexture(p2king);
        }}

        // sprite.setScale(55.0/p2pawn.getSize().x, 55.0/p2pawn.getSize().y);
        // cout << "SCALE: " << sprite.getScale().x << ","
        // << sprite.getScale().y << endl;
        // sprite.setColor(sf::Color::Yellow);
        // cout << "COLOR: " <<sprite.getScale().x << ","
        // << sprite.getScale().y << endl;

        // cout << "texture size: " << p2pawn.getSize().x << ","
        // << p2pawn.getSize().y << endl;
        // cout << "intendend scale: " << 55.0/p2pawn.getSize().x
        //  << "," <<  55.0/p2pawn.getSize().y << endl;
        sprite.setColor(sf::Color(0, 255, 0));
        // cout << "COLOR: " <<sprite.getScale().x << "," <<
        // sprite.getScale().y << endl;
        sprite.setScale(55.0/p2pawn.getSize().x, 55.0/p2pawn.getSize().y);
        // cout << "SCALE: " << sprite.getScale().x << "," <<
        // sprite.getScale().y << endl;

        // sprite.scale(55.0/p2pawn.getSize().x, 55.0/p2pawn.getSize().y);
        // cout << sprite.getScale().x << "," << sprite.getScale().y << endl;
        sprite.setPosition(36 + selectedPiece.first.second * 55,
        36 + selectedPiece.first.first * 55);
        target.draw(sprite);
    }

    if (turn) {
        sf::Sprite sprite;
        sprite.setTexture(arrow);
        sprite.setOrigin(arrow.getSize().x/2, arrow.getSize().y/2);
        sprite.scale(36.0/arrow.getSize().x, 36.0/arrow.getSize().y);
        sprite.setPosition(18, 4 * 64);
        sprite.setRotation(0);
        target.draw(sprite);
    } else {
        sf::Sprite sprite;
        sprite.setTexture(arrow);
        sprite.setOrigin(arrow.getSize().x/2, arrow.getSize().y/2);
        sprite.scale(36.0/arrow.getSize().x, 36.0/arrow.getSize().y);
        sprite.setPosition(18, 4 * 64);
        sprite.setRotation(180);
        target.draw(sprite);
    }

    // if(won)
    // {
    //     sf::Sprite sprite;
    //     sprite.setTexture(Win);
    //     sprite.scale(64.0/Win.getSize().x, 64.0/Win.getSize().y);
    //     sprite.setPosition(playerLocation.second * 64,
    //  playerLocation.first * 64);
    //     target.draw(sprite);
    // }
}
