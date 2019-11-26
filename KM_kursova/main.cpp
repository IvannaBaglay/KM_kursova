#include "function_interface.h"

sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!", sf::Style::Fullscreen);
sf::CircleShape shape(100.f);

void Draw()
{
    /*
    Node.Draw();
    Channel.Draw();
    Package.Draw();
    */
    window.draw(shape);
}

int main()
{  
    
    shape.setFillColor(sf::Color::Green);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(255, 255, 255));
        Draw();
        window.display();

    }

    return 0;
}