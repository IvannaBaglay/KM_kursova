#include <vector>

#include "function_interface.h"
#include "global_value.h"
#include "Node.h"
#include "Channel.h"
#include "Text.h"
#include "Algorithm.h"


static sf::RenderWindow window(sf::VideoMode(1920, 1080), "KM", sf::Style::Fullscreen);

std::vector<Node*> listOfNode;
std::vector<Channel*> listOfChannel;
std::vector<Text*> listOfTextOfWeightChannel;
std::vector<Text*> listOfTextOfTypeChannel;
Algorithm* algorithm;

bool WeMustChoseWeight = false;
bool WeMustChoseType = false;

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
           
            WeMustChoseType = true;
            WeMustChoseWeight = true;
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
    if (WeMustChoseWeight)
    {
        for (auto it : listOfTextOfWeightChannel)
        {

            window.draw(it->get_rectangle());
            window.draw(it->get_text());
        }
    }
    if (WeMustChoseType)
    {
        for (auto it : listOfTextOfTypeChannel)
        {
            window.draw(it->get_rectangle());
            window.draw(it->get_text());
        }
    }
        
    
    
    //Package.Draw();
    
    
}

void WorkEvent(sf::Event& event)
{
    if (!WeMustChoseWeight && !WeMustChoseType)
    {
        ClickMouseBottom(event);
        ClickKey(event);
    }
    else
    {       
        if (event.type == sf::Event::MouseButtonPressed)
        {
            CreateChannel(listOfChannel, listOfNode, listOfTextOfTypeChannel, listOfTextOfWeightChannel, sf::Mouse::getPosition());
        }
    }
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
    int x = 500;
    int y = 200;
    for (int i = 0; i < 3; i++)
    {
        x = 500;
        for (int j = 0; j < 3; j++)
        {
            listOfNode.push_back(new Node(sf::Vector2i(x, y)));
            x += 100;
        }
        y += 100;
    }    
    y = 200;
    for (int i = 0; i < 3; i++)
    {
        x = 900;
        for (int j = 0; j < 3; j++)
        {
            listOfNode.push_back(new Node(sf::Vector2i(x, y)));
            x += 100;
        }
        y += 100;
    }
    y = 600;
    for (int i = 0; i < 3; i++)
    {
        x = 700;
        for (int j = 0; j < 3; j++)
        {
            listOfNode.push_back(new Node(sf::Vector2i(x, y)));
            x += 100;
        }
        y += 100;
    }
}

void CollisionMouseAndNodes(std::vector<Node*>& listOfNode, sf::Vector2i mousePosition)
{
    for (auto it : listOfNode)
    {
        if (it->IsCollision(mousePosition))
        {
            it->set_isSelected();
        }
    }
}

void CollisonMouseAndChannel(std::vector <Channel*>& listOfChannel, sf::Vector2i mousePosition)
{

}

bool CollisonWithRectangle(int& value, std::vector<Text*>& listOfText, sf::Vector2i mousePosition, bool& isCollisionWithVectorOfRectangle)
{
    std::cout << "1";
    for (auto it : listOfText)
    {
        if (it->IsCollision(mousePosition))
        {
            value = it->get_value();
            isCollisionWithVectorOfRectangle = false;
            return true;
        }
    }
    return false;
}

void CreateChannel(std::vector<Channel*>& listOfChannel, std::vector<Node*>& listOfNode, std::vector<Text*>& listOfTextOfTypeChannel, std::vector<Text*>& listOfTextOfWeightChannel, sf::Vector2i mousePosition)
{

    static int weightOfChannel = -1;
    static int typeOfChannel = -1;
    
    if (WeMustChoseWeight)
    {
        CollisonWithRectangle(weightOfChannel, listOfTextOfWeightChannel, mousePosition, WeMustChoseWeight);
    }
    if (WeMustChoseType)
    {
        CollisonWithRectangle(typeOfChannel, listOfTextOfTypeChannel, mousePosition, WeMustChoseType);
    }

    if (!WeMustChoseType && !WeMustChoseWeight)
    {
        std::cout << "2";
        std::vector<Node*> listOfSelectNode;
        for (auto it : listOfNode)
        {
            if (it->get_isSelect())
            {
                listOfSelectNode.push_back(it);
            }
        }
        for (auto it1 : listOfSelectNode)
        {
            for (auto it2 : listOfSelectNode)
            {
                if (it1 != it2)
                {
                    bool weHaveChannelBetweenNode = false;
                    for (auto itChannel : listOfChannel)
                    {
                        if (itChannel->WeHaveChannelBetween(it1, it2))
                        {
                            weHaveChannelBetweenNode = true;
                        }
                    }
                    if (!weHaveChannelBetweenNode)
                    {
                        listOfChannel.push_back(new Channel(it1, it2, weightOfChannel, typeOfChannel));
                       
                    }
                    weHaveChannelBetweenNode = false;
                }
            }
        }

    }
   
}

void DeleteSelectedNode(std::vector<Channel*>& listOfChannel, std::vector<Node*>& listOfNode)
{
    std::vector<Node*> listOfUnselectedNode;
    std::vector<Channel*> listOfSelectedChannel;
    for (auto it : listOfNode)
    {
        if (!it->get_isSelect())
        {
            listOfUnselectedNode.push_back(it);
        }
        else
        {
            for (auto itChannel : listOfChannel)
            {
                if (itChannel->IsNodeInChannel(it))
                {
                    itChannel->set_Color(sf::Color(255, 0, 0));
                    listOfSelectedChannel.push_back(itChannel);
                }
            }
        }
    }
    listOfNode = listOfUnselectedNode;
    listOfChannel.erase(std::remove_if(listOfChannel.begin(), listOfChannel.end(), [&](Channel* channel)
        {
            if (std::find(listOfSelectedChannel.begin(), listOfSelectedChannel.end(), channel) != listOfSelectedChannel.end())
            {
                channel->set_Color(sf::Color::Green);
                return true;
            }
            return false;
        }
    ), listOfChannel.end());

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

    MyTask();
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