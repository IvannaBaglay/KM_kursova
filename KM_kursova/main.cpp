#include <vector>

#include "function_interface.h"
#include "global_value.h"
#include "Node.h"
#include "Channel.h"

sf::CircleShape shape(100.f);
static sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!", sf::Style::Fullscreen);

std::vector<Node*> listOfNode;

void ClickKey(sf::Event& event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        window.close();
    }
}

void ClickMouseBottom(sf::Event& event)
{
    switch (event.type)
    {
    case sf::Event::MouseButtonPressed:
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            listOfNode.push_back(new Node(sf::Mouse::getPosition())); break;
        }        
    default:
        break;
    }

}

void Draw()
{
    for (auto it : listOfNode)
    {    
        window.draw(it->get_nodeCircle());
    }
    /*
    Node.Draw();
    Channel.Draw();
    Package.Draw();
    */
    
}

void WorkEvent(sf::Event& event)
{
    ClickMouseBottom(event);
    ClickKey(event);
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
            WorkEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();

        }

        window.clear(sf::Color(255, 255, 255));
        
        Draw();
        window.display();

    }

    return 0;
}