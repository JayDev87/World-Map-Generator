#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <list> 
#include <iterator> 
#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include<cmath>
int main()
{
    float mapX = 0;
    float mapY = 0;
    float size = 0;
    int R = 1;
    int B = 1;
    int G = 1;
    int type = 1;
    int con = 1;
    std::cout << "<World Map Generator V1>";
    std::cout << "\n";
    std::cout << "-------------------------------------";
    std::cout << "\n";
    std::cout << "Enter the number of the map you want generated.";
    std::cout << "\n";
    std::cout << "-------------------------------------";
    std::cout << "\n";
    std::cout << "[1] QR Code(Black or white squares)";
    std::cout << "\n";
    std::cout << "[2] Random Colors (Rainbow from 255-0)";
    std::cout << "\n";
    std::cout << "[3] World Terrain Map (Randomly generated world map)";
    std::cout << "\n";
    std::cout << "-------------------------------------";
    std::cout << "\n";
    std::cout << "Map Num:"; std::cin >> type;
    std::cout << "The more size, the less time it takes. But the less size, the more tiles are going to fit on screen.";
    std::cout << "\n";
    std::cout << "The ideal size is 15.";
    std::cout << "\n";
    std::cout << "Size:"; std::cin >> size;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "World Map Generator");
    std::vector<sf::RectangleShape> box{};
    std::string command;
    while (window.isOpen())
    {

        for (size_t i{}; i < box.size(); i++)
        {
            window.draw(box[i]);
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
          
        }
        if (type == 1) 
        {
            sf::RectangleShape e{ sf::Vector2f(size, size) };
            rand() % 2 + 1;
            con = rand() % 2 + 1;
            if (con == 1)
            {
                R = 0; B = 0; G = 0;
            }
            if (con == 2)
            {
                R = 255; B = 255; G = 255;
            }

            e.setFillColor(sf::Color(R, B, G));
            e.setPosition(mapX, mapY);
            box.push_back(e);
            if (mapX <= 1950)
            {
                mapX += size;
            }
            if (mapX >= 1950)
            {
                mapY += size;
                mapX = 0;
            }
        }
        if (type == 2)
        {
            sf::RectangleShape e{ sf::Vector2f(size, size) };
            rand() % 2 + 1;
            R = rand() % 255 + 0;
            B = rand() % 255 + 0;
            G = rand() % 255 + 0;

            e.setFillColor(sf::Color(R, B, G));
            e.setPosition(mapX, mapY);
            box.push_back(e);
            if (mapX <= 1950)
            {
                mapX += size;
            }
            if (mapX >= 1950)
            {
                mapY += size;
                mapX = 0;
            }
        }
        if (type == 3)
        {
            sf::RectangleShape e{ sf::Vector2f(size, size) };
            con = rand() % 4 + 1;
            if (con == 1) 
            {
                e.setFillColor(sf::Color(0, 200, 0));
            }
            if (con == 4)
            {
                e.setFillColor(sf::Color(0, 200, 0));
            }
            if (con == 2)
            {
                e.setFillColor(sf::Color(210, 105, 30));
            }
            if (con == 3)
            {
                e.setFillColor(sf::Color(0, 100, 0));
            }
            e.setPosition(mapX, mapY);
            box.push_back(e);
            if (mapX <= 1950)
            {
                mapX += size;
            }
            if (mapX >= 1950)
            {
                mapY += size;
                mapX = 0;
            }
        }


        window.display();
    }
    return EXIT_SUCCESS;
}