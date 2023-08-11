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

void Checkers::pawn2King(std::map<std::pair<int, int>, char> &pieces,
 std::pair<int, int> pos) {
    auto x = pieces.find(pos);
    pieces.erase(x);
    pieces.insert(std::make_pair(pos, 'k'));
}

void Checkers::movePiece(std::map<std::pair<int, int>, char> &pieces,
 std::pair<int, int> newPos) {
    pieces.erase(selectedPiece.first);
    pieces.insert(std::make_pair(std::make_pair(newPos.first, newPos.second),
    selectedPiece.second.first));
    selectedPiece = std::make_pair(std::make_pair(-1, -1),
    std::make_pair('0', '0'));
}

void Checkers::nextMoves(std::pair<std::pair<int, int>, std::pair<char,
 char>> &piece,  std::map<std::pair<int, int>, char> &Moves) {
    int m, n;
    Moves.clear();
    if (piece.second.second == '1') {
            if (piece.second.first == 'p') {
                // if click is in a valid close square
                for (int j = -1; j < 2; j += 2) {
                    n = piece.first.first + 1;
                    m = piece.first.second + j;
                    if ((n >= 0 && n <= 7) && (m >= 0 && m <= 7) && (p2pieces.find(std::make_pair(n, m)) ==
                     p2pieces.end()) && (p1pieces.find(std::make_pair(n, m))
                     == p1pieces.end())) {
                        Moves.insert(std::make_pair(std::make_pair(n, m), 'r'));
                    }
                    auto x = p2pieces.find(std::make_pair(n, m));
                    if (x != p2pieces.end()) {
                        n = piece.first.first + 2;
                        m = piece.first.second + j * 2;
                        if ((n >= 0 && n <= 7) && (m >= 0 && m <= 7) && (p2pieces.find(std::make_pair(n, m)) ==
                         p2pieces.end()) && (p1pieces.find(std::make_pair(n, m))
                         == p1pieces.end())) {
                            Moves.insert(std::make_pair(std::make_pair(n,
                             m), 'j'));
                }}}}
            if (piece.second.first == 'k') {
                for (int i = -1; i < 2; i += 2) {
                    for (int j = -1; j < 2; j += 2) {
                        n = piece.first.first + i;
                        m = piece.first.second + j;
                        if ((n >= 0 && n <= 7) && (m >= 0 && m <= 7) && (p2pieces.find(std::make_pair(n, m)) ==
                         p2pieces.end()) && (p1pieces.find(std::make_pair(n, m))
                         == p1pieces.end())) {
                            Moves.insert(std::make_pair(std::make_pair(n,
                             m), 'r'));
                        }
                        auto x = p2pieces.find(std::make_pair(n, m));
                        if (x != p2pieces.end()) {
                            n = piece.first.first + i * 2;
                            m = piece.first.second + j * 2;
                            if ((n >= 0 && n <= 7) && (m >= 0 && m <= 7) && (p2pieces.find(std::make_pair(n, m)) ==
                             p2pieces.end()) && (p1pieces.find(
                                std::make_pair(n, m))
                             == p1pieces.end())) {
                                Moves.insert(std::make_pair(
                                    std::make_pair(n, m), 'j'));
    }}}}}} else { if (piece.second.second == '2') {
             if (piece.second.first == 'p') {
                    // if click is in a valid close square
                    for (int j = -1; j < 2; j += 2) {
                        n = piece.first.first - 1;
                        m = piece.first.second + j;
                        if ((n >= 0 && n <= 7) && (m >= 0 && m <= 7) && (p2pieces.find(std::make_pair(n, m)) ==
                         p2pieces.end()) && (p1pieces.find(std::make_pair(n, m))
                         == p1pieces.end())) {
                            Moves.insert(std::make_pair(
                                std::make_pair(n, m), 'r'));
                        }
                        auto x = p1pieces.find(std::make_pair(n, m));
                        if (x != p1pieces.end()) {
                            n = piece.first.first -2;
                            m = piece.first.second + j * 2;
                            if ((n >= 0 && n <= 7) && (m >= 0 && m <= 7) && (p2pieces.find(std::make_pair(n, m))
                             == p2pieces.end()) && (p1pieces.find(
                                std::make_pair(n, m))
                             == p1pieces.end())) {
                                Moves.insert(std::make_pair(
                                    std::make_pair(n, m), 'j'));
                    }}}}
                if (piece.second.first == 'k') {
                    for (int i = -1; i < 2; i += 2) {
                        for (int j = -1; j < 2; j += 2) {
                            n = piece.first.first + i;
                            m = piece.first.second + j;
                            if ((n >= 0 && n <= 7) && (m >= 0 && m <= 7) && (p2pieces.find(std::make_pair(n, m)) ==
                            p2pieces.end()) && (p1pieces.find(
                                std::make_pair(n, m))
                             == p1pieces.end())) {
                                Moves.insert(std::make_pair(
                                    std::make_pair(n, m), 'r'));
                            }
                            std::cout << "here1";
                            auto x = p1pieces.find(std::make_pair(n, m));
                            if (x != p1pieces.end()) {
                                std::cout << "here2";
                                n = piece.first.first + i * 2;
                                m = piece.first.second + j * 2;
                                if ((n >= 0 && n <= 7) && (m >= 0 && m <= 7) && (p2pieces.find(std::make_pair(n, m))
                                 == p2pieces.end()) && (p1pieces.find(
                                    std::make_pair(n, m)) == p1pieces.end())) {
                                        std::cout << "here3";
                                    Moves.insert(std::make_pair(
                                        std::make_pair(n, m), 'j'));
}}}}}}}}


void Checkers::checkMove(int x, int y) {
    double n, m;
    if (x > 36 && x < 36 + 55 * 8 && y > 36 && y < 36 + 55 * 8) {
        m = (x-36) / 55;
        n = (y-36) / 55;
        // if p1s turn
        for (auto moves : potMoves) {
            if (moves.first.first == n && moves.first.second == m) {
                if (moves.second == 'r') {
                    if (turn) {
                        movePiece(p1pieces, std::make_pair(n, m));
                    } else {
                        movePiece(p2pieces, std::make_pair(n, m));
                    }
                    turn = !turn;
                    break;
                }
                if (moves.second == 'j') {
                    if (turn) {
                        auto temp = std::make_pair(selectedPiece.first.first
                         - (selectedPiece.first.first - n)/2,
                         selectedPiece.first.second - (
                            selectedPiece.first.second - m)/2);
                        auto newPiece = std::make_pair(std::make_pair(n, m),
                         std::make_pair(selectedPiece.second.first, '1'));
                        movePiece(p1pieces, std::make_pair(n, m));
                        p2pieces.erase(temp);
                        selectedPiece = newPiece;
                        nextMoves(selectedPiece, potMoves);
                        auto temp2 = find_if(potMoves.begin(), potMoves.end(),
                         [](std::pair<std::pair<int, int>, char> piece) {
                            return piece.second == 'j';
                        });
                        if (temp2 == potMoves.end()) {
                            turn = !turn;
                            selectedPiece = std::make_pair(
                                std::make_pair(-1, -1), std::make_pair(
                                    '0', '0'));
                        }
                        if (n == 7) {
                            pawn2King(p1pieces, std::make_pair(n, m));
                    }} else {
                        auto temp = std::make_pair(selectedPiece.first.first
                         - (selectedPiece.first.first - n)/2,
                            selectedPiece.first.second - (
                                selectedPiece.first.second - m)/2);
                        auto newPiece = std::make_pair(std::make_pair(n, m),
                         std::make_pair(selectedPiece.second.first, '2'));
                        movePiece(p2pieces, std::make_pair(n, m));
                        p1pieces.erase(temp);
                        selectedPiece = newPiece;
                        nextMoves(selectedPiece, potMoves);
                        auto temp2 = find_if(potMoves.begin(),
                         potMoves.end(), [](std::pair<std::pair<int, int>,
                          char> piece) {
                            return piece.second == 'j';
                        });
                        if (temp2 == potMoves.end()) {
                            turn = !turn;
                            selectedPiece = std::make_pair(std::make_pair(
                                -1, -1), std::make_pair('0', '0'));
                        }
                        if (n == 0) {
                            pawn2King(p2pieces, std::make_pair(n, m));
                        }
                    }
                    break;
}}}
    if (p1pieces.empty()) {
        p1Win = true;
    }
    if (p2pieces.empty()) {
        p2Win = true;
    }
    std::map<std::pair<int, int>, char> noMoves;
    std::vector<bool> noMovesVector;
    for (auto x : p1pieces) {
        auto temp = std::make_pair(x.first, std::make_pair(x.second, '1'));
        nextMoves(temp, noMoves);
        if (noMoves.empty())
            noMovesVector.push_back(true);
    }
    if (noMovesVector.empty())
        p1Win = true;
    noMovesVector.clear();
    for (auto x : p2pieces) {
        auto temp = std::make_pair(x.first, std::make_pair(x.second, '2'));
        nextMoves(temp, noMoves);
        if (noMoves.empty())
            noMovesVector.push_back(true);
    }
    if (noMovesVector.empty())
        p2Win = true;
    noMovesVector.clear();
}}





bool Checkers::pieceSelected() {
    return selectedPiece.second.second != '0';
}
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

    potMoves.clear();
    nextMoves(selectedPiece, potMoves);
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
    loserFont.loadFromFile("checkers/UbuntuMono-R.ttf");

    p1Win = false;
    p2Win = false;
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
}}}}}

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


    if (p1Win) {
        sf::Text text;
        text.setFont(loserFont);
        text.setPosition(0, 64 * 4);
        text.setColor(sf::Color::White);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        text.setCharacterSize(64);
        text.setString("Player 2 Wins!");
        target.draw(text);
    }
    if (p2Win) {
        sf::Text text;
        text.setFont(loserFont);
        text.setPosition(0, 64 * 4);
        text.setColor(sf::Color::White);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        text.setCharacterSize(64);
        text.setString("Player 1 Wins!");
        target.draw(text);
    }
}
