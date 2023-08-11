#include "Sokaban.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>



using namespace std;

Sokaban::Sokaban(){
    Wall.loadFromFile("sokoban/block_06.png");
    Box.loadFromFile("sokoban/crate_03.png");
    Empty.loadFromFile("sokoban/ground_01.png");
    Storage.loadFromFile("sokoban/ground_04.png");
    Player[0].loadFromFile("sokoban/player_05.png");
    Player[1].loadFromFile("sokoban/player_08.png");
    Player[2].loadFromFile("sokoban/player_17.png");
    Player[3].loadFromFile("sokoban/player_20.png");
}

Sokaban::~Sokaban(){
    for(int i = 0; i < height; i++){
        delete[] map[i];
    }
    delete[] map;
}
int Sokaban::getHeight() const {return height;}
int Sokaban::getWidth() const {return width;}
void Sokaban::setHeight(int h) {height = h;}
void Sokaban::setWidth(int w) {width = w;}
char Sokaban::operator[](pair<int,int> p) const {return map[p.first][p.second];}

istream& operator>>(istream& in, Sokaban& s){
    in >> s.height >> s.width;
    s.map = new char*[s.height];
    for(int i = 0; i < s.height; i++){
        s.map[i] = new char[s.width];
        for(int j = 0; j < s.width; j++){
            in >> s.map[i][j];
            if(s.map[i][j] == '@'){
                s.playerLocation.first = i;
                s.playerLocation.second = j;
            }
            if(s.map[i][j] == 'A'){
                s.boxLocation.push_back(make_pair(i,j));}
            if(s.map[i][j] == 'a'){
                s.storageLocation.push_back(make_pair(i,j));
            }
        }
    }
    return in;
}

void Sokaban::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            sf::Sprite sprite;
            switch(map[i][j]){
                case '#':
                    sprite.setTexture(Wall);
                    break;
                case 'A':
                    sprite.setTexture(Box);
                    break;
                case '.':
                    sprite.setTexture(Empty);
                    break;
                case 'a':
                    sprite.setTexture(Storage);
                    break;
                case '@':
                    sprite.setTexture(Player[0]);
                    break;
                case 'S':
                    sprite.setTexture(Player[0]);
                    break;
                case 'N':
                    sprite.setTexture(Player[1]);
                    break;
                case 'E':
                    sprite.setTexture(Player[2]);
                    break;
                case 'W':
                    sprite.setTexture(Player[3]);
                    break;
            }
            sprite.setPosition(j * 64, i * 64);
            target.draw(sprite);
        }
    }
}