#include <SFML/Graphics.hpp>
#include <iostream>

#define WIDTH 600
#define HEIGHT 600

void render(sf::RenderWindow* window)
{
    window->clear();

    float r = 100.0;
    sf::CircleShape circle(r);
    circle.setFillColor(sf::Color::White);
    circle.setPosition(WIDTH/2 - r,HEIGHT/2 - r);

    window->draw(circle);
}

int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT),"Langton's Ant");

    while(window.isOpen())
    {
        sf::Event ev;
        while(window.pollEvent(ev))
        {
            if(ev.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        render(&window);
        window.display();
    }

    return 0;
}