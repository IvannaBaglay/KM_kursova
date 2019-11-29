#include <vector>

#include "function_interface.h"
#include "global_value.h"
#include "Node.h"
#include "Channel.h"
#include "Text.h"

#define WEIGHT_RECTANGLE 100.0;

sf::CircleShape shape(100.f);
static sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");

std::vector<Node*> listOfNode;
std::vector<Channel*> listOfChannel;
std::vector<Text*> listOfText;

bool isVisibleText = false;

void ClickKey(sf::Event& event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        window.close();
    }
    switch (event.type)
    {
    case sf::Event::KeyPressed:
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
        {
            CreateChannel(listOfChannel, listOfNode);
            isVisibleText = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            DeleteSelectedNode(listOfChannel, listOfNode);
        }
        break;
    default:
        break;
    }
}

void ClickMouseBottom(sf::Event& event)
{
    switch (event.type)
    {
    case sf::Event::MouseButtonPressed:
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            listOfNode.push_back(new Node(sf::Mouse::getPosition()));
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            CollisionMouseAndNodes(listOfNode, sf::Mouse::getPosition());
        }
        break;
    default:
        break;
    }

}

void Draw()
{


    for (auto it : listOfChannel)
    {
        window.draw(it->get_line(), 2, sf::Lines);
    }
    for (auto it : listOfNode)
    {
        window.draw(it->get_nodeCircle());
    }
    if (isVisibleText)
    {
        for (auto it : listOfText)
        {

            window.draw(it->get_rectangle());
            window.draw(it->get_text());
        }
    }
    //Package.Draw();
    
    
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

void InputText()
{
    listOfText.push_back(new Text("3", 10, 10));
    listOfText.push_back(new Text("3", 110, 10));
    listOfText.push_back(new Text("3", 210, 10));
}

int main()
{  
    InputText();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            WorkEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();

        }

        window.clear(sf::Color::White);
        
        Draw();
        window.display();

    }
    for (auto it : listOfNode)
    {
        std::cout << it->get_index();
    }
    for (auto it : listOfChannel)
    {
        std::cout << it->get_node1_index();
        std::cout << it->get_node2_index();
    }

    return 0;
}