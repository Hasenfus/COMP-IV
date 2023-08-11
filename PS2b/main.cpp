#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Sokaban.h"


using namespace std;

int main(int arg, char* argc[])
{
    
    if(arg == 1)
        return -1;
    for(int i = 1; i < arg; i++)
    {
        Sokaban s;
        fstream f(argc[i], ios::in);
        f >> s;

        sf::RenderWindow window(sf::VideoMode(s.getWidth() * 64, s.getHeight() * 64), argc[i]);
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event)) 
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::KeyPressed)
                {   
                    if(event.key.code == sf::Keyboard::R)
                    {
                        f.clear();
                        f.seekg(0, ios::beg);
                        f >> s;
                    }
                    else
                        s.movePlayer(event.key.code);
                }
                
            }
            window.clear();
            window.draw(s);
            window.display();
        }
    }

    return 0;
}

