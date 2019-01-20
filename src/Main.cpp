#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
//#include <iostream>

#include "Grid.h"
#include "Cell.h"
#include "Ant.h"

#define MILLIS_DELAY 5

Grid *g;
Ant *ant;
sf::RenderWindow *window;

void update()
{
    int x = ant->getX();
    int y = ant->getY();
    sf::RectangleShape space(sf::Vector2f(GRID_SIZE,GRID_SIZE));
    space.setPosition(x*GRID_SIZE,y*GRID_SIZE);
    if(g->getCell(x,y)->isWhite())
    {
        ant->turnLeft();
        space.setFillColor(sf::Color::Black);
    } else
    {
        ant->turnRight();
        space.setFillColor(sf::Color::White);
    }
    g->getCell(x,y)->invert();
    window->draw(space);
    ant->moveForward();
}

int main(int argc, char** argv)
{
    g = new Grid();
    ant = new Ant(GRID_WIDTH/2,GRID_HEIGHT/2);
    window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT),"Langton's Ant");
    sf::RectangleShape space(sf::Vector2f(WIDTH,HEIGHT));
    space.setFillColor(sf::Color::White);
    window->draw(space);
    window->display();

    while(window->isOpen())
    {
        //std::cout << "Main loop!" << std::endl;
        sf::Event ev;
        while(window->pollEvent(ev))
        {
            if(ev.type == sf::Event::Closed)
            {
                window->close();
            }
        }

        update();
        window->display();

        std::this_thread::sleep_for (std::chrono::milliseconds(MILLIS_DELAY));
    }

    delete g;
    delete window;
    delete ant;

    return 0;
}