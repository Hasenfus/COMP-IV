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
    GBox.loadFromFile("sokoban/crate_03G.png");
    Box.loadFromFile("sokoban/crate_03.png");
    Empty.loadFromFile("sokoban/ground_01.png");
    Storage.loadFromFile("sokoban/ground_04.png");
    Player[1].loadFromFile("sokoban/player_05.png");
    Player[0].loadFromFile("sokoban/player_08.png");
    Player[2].loadFromFile("sokoban/player_17.png");
    Player[3].loadFromFile("sokoban/player_20.png");
    Win.loadFromFile("sokoban/win.png");
    
}
void Sokaban::isWon()
{
    if (storageLocation.size() < boxLocation.size()){
        for(auto y : storageLocation)
        {
            vector<pair<int,int>>::iterator x = find_if(boxLocation.begin(), boxLocation.end(), [y](pair<int,int> p){return p.first == y.first && p.second == y.second;});
            if(x == boxLocation.end()){
                won = false;
                return;}
        }}
    else{
        for(auto y : boxLocation)
        {
            vector<pair<int,int>>::iterator x = find_if(storageLocation.begin(), storageLocation.end(), [y](pair<int,int> p){return p.first == y.first && p.second == y.second;});
            if(x == storageLocation.end()){
                won = false;
                return;}
        }}
    
    won = true;
}
void Sokaban::movePlayer(sf::Keyboard::Key k)
{
    vector<pair<int,int>> boxes;
    int i = 1;
    if(k == sf::Keyboard::Up || k == sf::Keyboard::W)
    {
        if(map[playerLocation.first - 1][playerLocation.second] == '.' || map[playerLocation.first - 1][playerLocation.second] == 'a')
        {   
            vector<pair<int,int>>::iterator x = find_if(boxLocation.begin(), boxLocation.end(), [this,i](pair<int,int> p){return p.first == playerLocation.first - i && p.second == playerLocation.second;});
            if(x != boxLocation.end())
            {
                while(x != boxLocation.end())
                {
                    if(map[playerLocation.first - (i+1)][playerLocation.second] == '.' || map[playerLocation.first - (i+1)][playerLocation.second] == 'a')
                    {
                        boxes.push_back(*x);
                    }
                    i++;
                    x = find_if(boxLocation.begin(), boxLocation.end(), [this,i](pair<int,int> p){return p.first == playerLocation.first - i && p.second == playerLocation.second;});
                }
                if(map[playerLocation.first - (i)][playerLocation.second] == '.' || map[playerLocation.first - (i)][playerLocation.second] == 'a')
                {
                    for(auto y : boxes)
                    {
                        vector<pair<int,int>>::iterator x = find_if(boxLocation.begin(), boxLocation.end(), [y](pair<int,int> p){return p.first == y.first && p.second == y.second;});                        
                        x->first--;
                    }
                    playerLocation.first--;
                }
            }
            else
            {
                playerLocation.first--;
            }
        }
        direction = 'N';
    }
    if(k == sf::Keyboard::Down || k == sf::Keyboard::S)
    {
        if(map[playerLocation.first + 1][playerLocation.second] == '.' || map[playerLocation.first + 1][playerLocation.second] == 'a')
        {
            vector<pair<int,int>>::iterator x = find_if(boxLocation.begin(), boxLocation.end(), [this](pair<int,int> p){return (p.first == (playerLocation.first + 1)) && p.second == playerLocation.second;});
            if(x != boxLocation.end())
            {
                while(x != boxLocation.end())
                {
                    if(map[playerLocation.first + (i+1)][playerLocation.second] == '.' || map[playerLocation.first + (i+1)][playerLocation.second] == 'a')
                    {
                        boxes.push_back(*x);
                    }
                    i++;
                    x = find_if(boxLocation.begin(), boxLocation.end(), [this,i](pair<int,int> p){return (p.first == (playerLocation.first + i)) && p.second == playerLocation.second;});
                }
                if(map[playerLocation.first + (i)][playerLocation.second] == '.' || map[playerLocation.first + (i)][playerLocation.second] == 'a')
                {
                    for(auto y : boxes)
                    {
                        vector<pair<int,int>>::iterator x = find_if(boxLocation.begin(), boxLocation.end(), [y](pair<int,int> p){return p.first == y.first && p.second == y.second;});                        
                        x->first++;
                    }
                    playerLocation.first++;
                }
            }
            else
            {
                playerLocation.first++;
            }
        
        }
        direction = 'S';
    }
    if(k == sf::Keyboard::Left || k == sf::Keyboard::A)
    {
        if(map[playerLocation.first][playerLocation.second - 1] == '.' || map[playerLocation.first][playerLocation.second - 1] == 'a')
        {
            vector<pair<int,int>>::iterator x = find_if(boxLocation.begin(), boxLocation.end(), [this](pair<int,int> p){return p.first == playerLocation.first && p.second == playerLocation.second - 1;});
            if(x != boxLocation.end())
            {
                while(x != boxLocation.end())
                {
                    if(map[playerLocation.first][playerLocation.second - (i+1)] == '.' || map[playerLocation.first][playerLocation.second - (i+1)] == 'a')
                    {
                        boxes.push_back(*x);
                    }
                    i++;
                    x = find_if(boxLocation.begin(), boxLocation.end(), [this,i](pair<int,int> p){return p.first == playerLocation.first  && p.second == (playerLocation.second - i);});
                }
                if(map[playerLocation.first][playerLocation.second- (i)] == '.' || map[playerLocation.first][playerLocation.second - (i)] == 'a')
                {
                    for(auto y : boxes)
                    {
                        vector<pair<int,int>>::iterator x = find_if(boxLocation.begin(), boxLocation.end(), [y](pair<int,int> p){return p.first == y.first && p.second == y.second;});                        
                        x->second--;
                    }
                    playerLocation.second--;
                }
            }
            else
            {
                playerLocation.second--;
            }
        }
        direction = 'W';
    }
    if(k == sf::Keyboard::Right || k == sf::Keyboard::D)
    {
        if(map[playerLocation.first][playerLocation.second + 1] == '.' || map[playerLocation.first][playerLocation.second + 1] == 'a')
        {
            vector<pair<int,int>>::iterator x = find_if(boxLocation.begin(), boxLocation.end(), [this](pair<int,int> p){return p.first == playerLocation.first && (p.second == (playerLocation.second + 1));});
            if(x != boxLocation.end())
            {
                while(x != boxLocation.end())
                {
                    if(map[playerLocation.first][playerLocation.second + (i+1)] == '.' || map[playerLocation.first][playerLocation.second + (i+1)] == 'a')
                    {
                        boxes.push_back(*x);
                    }
                    i++;
                    x = find_if(boxLocation.begin(), boxLocation.end(), [this,i](pair<int,int> p){return (p.first == playerLocation.first) && (p.second == (playerLocation.second + i));});
                }
                if(map[playerLocation.first][playerLocation.second + i] == '.' || map[playerLocation.first][playerLocation.second + i] == 'a')
                {
                    for(auto y : boxes)
                    {
                        vector<pair<int,int>>::iterator x = find_if(boxLocation.begin(), boxLocation.end(), [y](pair<int,int> p){return (p.first == y.first) && (p.second == y.second);});
                        x->second++;
                    }
                    playerLocation.second++;
                }
            }
            else
            {
                playerLocation.second++;
            }
        }
        direction = 'E';
    }
    isWon();
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
    s.won = false;
    s.map = new char*[s.height];
    s.boxLocation.clear();
    s.storageLocation.clear();
    for(int i = 0; i < s.height; i++){
        s.map[i] = new char[s.width];
        for(int j = 0; j < s.width; j++){
            char x;
            in >> x;
            if(x == '@'){
                s.playerLocation.first = i;
                s.playerLocation.second = j;
                s.map[i][j] = '.';
                s.direction = '@';
            }
            if(x == 'A'){
                s.boxLocation.push_back(make_pair(i,j));}
                s.map[i][j] = '.';
            if(x == 'a'){
                s.storageLocation.push_back(make_pair(i,j));
                s.map[i][j] = x;
            }
            if(x == '#'){
                s.map[i][j] = x;
            }
            if(x == '.'){
                s.map[i][j] = x;
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
                case '.':
                    sprite.setTexture(Empty);
                    break;
                case 'a':
                    sprite.setTexture(Storage);
                    break;
            }
            sprite.setPosition(j * 64, i * 64);
            target.draw(sprite);
        }
    }
    
    for(auto x: boxLocation){
        sf::Sprite sprite;
        auto y = find_if(storageLocation.begin(),  storageLocation.end(), [x](pair<int,int> p){return (p.first == x.first) && (p.second == x.second);});
        if(y != storageLocation.end())
            sprite.setTexture(GBox);
        else   
            sprite.setTexture(Box);
        sprite.setPosition(x.second * 64, x.first * 64);
        target.draw(sprite);
        
    }
    sf::Sprite player;
    switch(direction){
        case '@':
            player.setTexture(Player[0]);
            break;
        case 'N':
            player.setTexture(Player[0]);
            break;
        case 'S':
            player.setTexture(Player[1]);
            break;
        case 'E':
            player.setTexture(Player[2]);
            break;
        case 'W':
            player.setTexture(Player[3]);
            break;
    }
    player.setPosition(playerLocation.second * 64, playerLocation.first * 64);
    target.draw(player);

    if(won)
    {
        sf::Sprite sprite;
        sprite.setTexture(Win);
        sprite.scale(64.0/Win.getSize().x, 64.0/Win.getSize().y);
        sprite.setPosition(playerLocation.second * 64, playerLocation.first * 64);
        target.draw(sprite);
    }
}
