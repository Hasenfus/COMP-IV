// Hunter M Hasenfus
// Computing IV
// Prof. Rykalova
//
//
 
#include <iostream>
#include <cstdlib>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.h" 

#define DISPLAY 1

using namespace std;

void transform(sf::Image&, FibLFSR*);

int main(int argc, char* argv[])
{
    if (argc != 4){
        cout << argc << endl;
        return -1;}
    
    FibLFSR seed(argv[3]);

    sf::Image input;
    input.loadFromFile(argv[1]);
    sf::Image output;
    output.loadFromFile(argv[1]);;

    transform(output, &seed);

    sf::Texture texture1;
    texture1.loadFromImage(input);
    sf::Texture texture2;
    texture2.loadFromImage(output);
    sf::Sprite sprite1(texture1);
    sf::Sprite sprite2(texture2);

    sf::RenderWindow window1(sf::VideoMode(sprite1.getTexture()->getSize().x * sprite1.getScale().x, sprite1.getTexture()->getSize().y * sprite1.getScale().y ), "Before");
    sf::RenderWindow window2(sf::VideoMode(sprite1.getTexture()->getSize().x * sprite1.getScale().x, sprite1.getTexture()->getSize().y * sprite1.getScale().y ), "After");
    if(DISPLAY)
    {    
        while (window1.isOpen() && window2.isOpen()) 
        {
            sf::Event event;
            while (window1.pollEvent(event)) 
            {
                if (event.type == sf::Event::Closed)
                window1.close();
            }
            while (window2.pollEvent(event)) 
            {
                if (event.type == sf::Event::Closed)
                    window2.close();
            }
            window1.clear();
            window1.draw(sprite1);
            window1.display();
            window2.clear();
            window2.draw(sprite2);
            window2.display();
        }
    }

    output.saveToFile(argv[2]);

 
 
    return 0;
}

void transform(sf::Image& input, FibLFSR* seed)
{
    sf::Color p;
    cout << input.getSize().x << " " << input.getSize().y << endl;
    for(int i = 0; i < input.getSize().x; i++)
    {
        for(int j = 0; j < input.getSize().y; j++)
        {
            p = input.getPixel(i,j);
            p.r = p.r ^ seed->generate(8);
            p.g = p.g ^ seed->generate(8);
            p.b = p.b ^ seed->generate(8);
            input.setPixel(i,j,p);
        }
    }
}
