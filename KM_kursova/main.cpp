#include <vector>

#include "function_interface.h"
#include "global_value.h"
#include "Node.h"
#include "Channel.h"
#include "Text.h"
#include "Algorithm.h"
#include "Package.h"
#include "Send.h"


static sf::RenderWindow window(sf::VideoMode(1920, 1080), "KM", sf::Style::Fullscreen);

std::vector<Node*> listOfNode;
std::vector<Channel*> listOfChannel;
std::vector<Node*> listOfPath;
std::vector<Text*> listOfTextOfWeightChannel;
std::vector<Text*> listOfTextOfTypeChannel;
std::vector<Text*> listOfTextTypeMethod;

Algorithm* algorithm;

Message* message;

Send send;

bool WeMustChoseWeight = false;
bool WeMustChoseTypeOfChannel = false;
bool WeMustChoseTypeSend = false;

int indexOfEndNode = -1;
int indexOfStartNode = -1;

void DeleteLabel()
{
    for (auto it : listOfNode)
    {
        it->set_label(tentative);
        it->set_lenght(INFINITY);
        it->set_predecessor(-1);
        it->set_isUsingInAlgorithm(false);
        if (it->get_isSelect())
        {
            it->set_isSelected();
        }
    }
}

void FindSelectNode(int& value)
{
    int i = 0;
    for (auto it : listOfNode)
    {
        if (it->get_isSelect())
        {
            value = i;
        }
        i++;
    }
}

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
           
            WeMustChoseTypeOfChannel = true;
            WeMustChoseWeight = true;
            CreateChannel(listOfChannel, listOfNode, listOfTextOfTypeChannel, listOfTextOfWeightChannel, sf::Mouse::getPosition());            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            DeleteSelectedNode(listOfChannel, listOfNode);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            SelectedNodeInStation(listOfNode);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        {           
            FindSelectNode(indexOfStartNode);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        {
            FindSelectNode(indexOfEndNode);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            message = new Message(5000, 1024, indexOfEndNode);

            //Package *p = (*message)[0];
            Package* p;
            int numberOfPath = message->get_numberOfPackage();
            for (int i = 0; i < numberOfPath; i++)
            {    
                DeleteLabel();
                p = (*message)[i];
                algorithm = new Algorithm(listOfNode, listOfChannel, indexOfStartNode, indexOfEndNode);
                listOfPath = algorithm->Start(listOfNode, listOfChannel);
                send.SendPackage(p, listOfPath, Datagram);
               
            }
            message->set_indexOfDestinationNode(listOfNode[indexOfStartNode]->get_index());
            send.SendMessage(message, listOfNode, indexOfStartNode, listOfPath.size());
            
        }        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {          
            WeMustChoseTypeSend = true;
            listOfPath.clear();
        }
        break;
    default:
        break;
    }
}



void SelectedNodeInStation(std::vector<Node*> listOfNode)
{
    for (auto it : listOfNode)
    {
        if (it->get_isSelect())
        {
            it->set_isStation(true);
            it->set_isSelected();                 
        }
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
        window.draw(it->get_addedInformation());
    }
    if (WeMustChoseWeight)
    {
        for (auto it : listOfTextOfWeightChannel)
        {

            window.draw(it->get_rectangle());
            window.draw(it->get_text());
        }
    }
    if (WeMustChoseTypeOfChannel)
    {
        for (auto it : listOfTextOfTypeChannel)
        {
            window.draw(it->get_rectangle());
            window.draw(it->get_text());
        }
    }   
    if (WeMustChoseTypeSend)
    {
        for (auto it : listOfTextTypeMethod)
        {
            window.draw(it->get_rectangle());
            window.draw(it->get_text());
        }
    }
    //Package.Draw();
}

void WorkEvent(sf::Event& event)
{
    if (!WeMustChoseWeight && !WeMustChoseTypeOfChannel)
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
}

void MyTaskCreateChannel()
{
    listOfChannel.push_back(new Channel(listOfNode[0], listOfNode[1], 20));
    listOfChannel.push_back(new Channel(listOfNode[1], listOfNode[3], 3));
    listOfChannel.push_back(new Channel(listOfNode[3], listOfNode[6], 10));
    listOfChannel.push_back(new Channel(listOfNode[3], listOfNode[7], 12));
    listOfChannel.push_back(new Channel(listOfNode[3], listOfNode[4], 30));
    listOfChannel.push_back(new Channel(listOfNode[4], listOfNode[2], 8));
    listOfChannel.push_back(new Channel(listOfNode[4], listOfNode[8], 17));
    listOfChannel.push_back(new Channel(listOfNode[4], listOfNode[5], 27));
    listOfChannel.push_back(new Channel(listOfNode[1], listOfNode[2], 12));
    listOfChannel.push_back(new Channel(listOfNode[1], listOfNode[4], 30));
    listOfChannel.push_back(new Channel(listOfNode[3], listOfNode[0], 8));
    listOfChannel.push_back(new Channel(listOfNode[7], listOfNode[8], 17));
    listOfChannel.push_back(new Channel(listOfNode[2], listOfNode[5], 27));

    listOfChannel.push_back(new Channel(listOfNode[9], listOfNode[10], 20));
    listOfChannel.push_back(new Channel(listOfNode[10], listOfNode[14], 3));
    listOfChannel.push_back(new Channel(listOfNode[12], listOfNode[16], 10));
    listOfChannel.push_back(new Channel(listOfNode[11], listOfNode[14], 12));
    listOfChannel.push_back(new Channel(listOfNode[11], listOfNode[10], 30));
    listOfChannel.push_back(new Channel(listOfNode[13], listOfNode[14], 8));
    listOfChannel.push_back(new Channel(listOfNode[12], listOfNode[17], 17));
    listOfChannel.push_back(new Channel(listOfNode[17], listOfNode[16], 27));
    listOfChannel.push_back(new Channel(listOfNode[12], listOfNode[15], 30));
    listOfChannel.push_back(new Channel(listOfNode[12], listOfNode[10], 8));
    listOfChannel.push_back(new Channel(listOfNode[13], listOfNode[17], 17));
    listOfChannel.push_back(new Channel(listOfNode[17], listOfNode[14], 27));
    listOfChannel.push_back(new Channel(listOfNode[12], listOfNode[13], 6));

    listOfChannel.push_back(new Channel(listOfNode[18], listOfNode[19], 20));
    listOfChannel.push_back(new Channel(listOfNode[22], listOfNode[23], 3));
    listOfChannel.push_back(new Channel(listOfNode[26], listOfNode[23], 10));
    listOfChannel.push_back(new Channel(listOfNode[25], listOfNode[22], 12));
    listOfChannel.push_back(new Channel(listOfNode[24], listOfNode[22], 30));
    listOfChannel.push_back(new Channel(listOfNode[20], listOfNode[19], 8));
    listOfChannel.push_back(new Channel(listOfNode[20], listOfNode[23], 17));
    listOfChannel.push_back(new Channel(listOfNode[18], listOfNode[21], 27));
    listOfChannel.push_back(new Channel(listOfNode[22], listOfNode[26], 30));
    listOfChannel.push_back(new Channel(listOfNode[22], listOfNode[18], 17));
    listOfChannel.push_back(new Channel(listOfNode[21], listOfNode[20], 3));
    listOfChannel.push_back(new Channel(listOfNode[21], listOfNode[24], 5));

    listOfChannel.push_back(new Channel(listOfNode[5], listOfNode[12], 3));
    listOfChannel.push_back(new Channel(listOfNode[18], listOfNode[15], 5));
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
    MyTaskCreateChannel();
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
    if (WeMustChoseTypeOfChannel)
    {
        CollisonWithRectangle(typeOfChannel, listOfTextOfTypeChannel, mousePosition, WeMustChoseTypeOfChannel);
    }

    if (!WeMustChoseTypeOfChannel && !WeMustChoseWeight)
    {
        std::vector<Node*> listOfSelectNode;
        for (auto it : listOfNode)
        {
            if (it->get_isSelect())
            {
                it->set_isSelected();
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
                                        "27", "29","30", "random" };
    int x = 10;
    int y = 10;
    for (auto it : weightOfChannel)
    {
        listOfTextOfWeightChannel.push_back(new Text(it, x, y, true));
        y += 55;
    }
    std::string typeOfChannel[] = { "duplex", "half-duplex" };
    x = 10 + 105;
    y = 10;
    for (auto it : typeOfChannel)
    {
        listOfTextOfTypeChannel.push_back(new Text(it, x, y, false));
        y += 55;
    }
    std::string typeOfMethod[] = {"Datagram","Logic","Virtual"};
    x = 10 + 2 * 105;
    y = 10;
    for (auto it : typeOfMethod)
    {
        listOfTextTypeMethod.push_back(new Text(it, x, y, false));
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


    return 0;
}