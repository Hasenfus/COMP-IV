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
     void pawn2King(std::map<std::pair<int, int>, char> &pieces,
      std::pair<int, int> pos);
     void recognizePiece(int x, int y);
     bool pieceSelected();
     void checkMove(int x, int y);
     void nextMoves(std::pair<std::pair<int, int>, std::pair<char,
      char>> &piece, std::map<std::pair<int, int>, char> &Moves);

 private:
     void movePiece(std::map<std::pair<int, int>, char> &pieces,
      std::pair<int, int> newPos);
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
     sf::Font loserFont;

     std::map<std::pair<int, int>, char> potMoves;

     std::pair<std::pair<int, int>, std::pair<char, char>> selectedPiece;

     //  std::vector<std::pair<int, int>> p1pawns;
     //  std::vector<std::pair<int, int>> p1kings;

     //  std::vector<std::pair<int, int>> p2pawns;
     //  std::vector<std::pair<int, int>> p2kings;

     std::map<std::pair<int, int>, char> p1pieces;
     std::map<std::pair<int, int>, char> p2pieces;

     bool p1Win;
     bool p2Win;
};

#endif  // CHECKERS_H_
