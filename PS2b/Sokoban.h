#ifndef SOKABAN_H
#define SOKABAN_H


#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

class Sokaban: public sf::Drawable{
    public:
        Sokaban();
        friend istream& operator>>(istream& in, Sokaban& s);
        ~Sokaban();
        int getHeight() const;
        int getWidth() const;
        void setHeight(int h);
        void setWidth(int w);
        char operator[](pair<int,int> p) const;
        void movePlayer(sf::Keyboard::Key k);
        void isWon();
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        int height;
        int width;
        char** map;
        sf::Texture Wall;
        sf::Texture Box;
        sf::Texture GBox;
        sf::Texture Empty;
        sf::Texture Storage;
        sf::Texture Player[4];
        sf::Texture Win;
        bool won;
        pair<int,int> playerLocation;
        vector<pair<int,int>> boxLocation;
        vector<pair<int,int>> storageLocation;
        char direction;
};

#endif