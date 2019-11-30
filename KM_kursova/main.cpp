#include <vector>

#include "function_interface.h"
#include "global_value.h"
#include "Node.h"
#include "Channel.h"
#include "Text.h"
#include "Algorithm.h"

static sf::RenderWindow window(sf::VideoMode(1920, 1080), "KM");

std::vector<Node*> listOfNode;
std::vector<Channel*> listOfChannel;
std::vector<Text*> listOfTextOfWeightChannel;
std::vector<Text*> listOfTextOfTypeChannel;
Algorithm* algorithm;

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
           
            CreateChannel(listOfChannel, listOfNode, listOfTextOfTypeChannel, listOfTextOfWeightChannel, sf::Mouse::getPosition());
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            DeleteSelectedNode(listOfChannel, listOfNode);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            algorithm = new Algorithm();
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
        window.draw(it->get_text());
    }
    for (auto it : listOfNode)
    {
        window.draw(it->get_nodeCircle());
        window.draw(it->get_text());
    }
    for (auto it : listOfTextOfWeightChannel)
    {

        window.draw(it->get_rectangle());
        window.draw(it->get_text());
    }
    for (auto it : listOfTextOfTypeChannel)
    {
        window.draw(it->get_rectangle());
        window.draw(it->get_text());
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

void MyTask()
{
    int x = 100;
    int y = 200;
    for (int i = 0; i < 10; i++)
    {
        listOfNode.push_back(new Node(sf::Vector2i(x, y)));
        x += 100;
    }

}

void InputText()
{
    std::string weightOfChannel[] = { "3","5","6","8","10","12","17","20","25",
                                        "27", "29","30" };
    int x = 10;
    int y = 10;
    for (auto it : weightOfChannel)
    {
        listOfTextOfWeightChannel.push_back(new Text(it, x, y));
        y += 55;
    }
    std::string typeOfChannel[] = { "duplex", "half-duplex" };
    x = 10 + 105;
    y = 10;
    for (auto it : typeOfChannel)
    {
        listOfTextOfTypeChannel.push_back(new Text(it, x, y));
        y += 55;
    }
}

int main()
{  

    //MyTask();
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
    std::cout << "\n";
    for (auto it : listOfChannel)
    {
        std::cout << it->get_node1_index();
        std::cout << it->get_node2_index();
    }

    return 0;
}