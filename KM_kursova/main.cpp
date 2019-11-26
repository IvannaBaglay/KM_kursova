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

void WorkEvent()
{
    /*
    ClickMouse
    Right botton on free place create new node linker 
    Left botton on free place create new station
    right click on node/station to select
    
    Keyboard
    Click C when we have 2 select node create Channel 
    and display menu for input weight of channel
    */
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