#include "function_interface.h"
#include "Node.h"
#include "Text.h"

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

void CollisonMouseAndChannel(std::vector <Channel*> & listOfChannel, sf::Vector2i mousePosition)
{

}

bool CollisonWithRectangle(int& weight, std::vector<Text*>& listOfText, sf::Vector2i mousePosition)
{
    for (auto it : listOfText)
    {
        if (it->IsCollision(mousePosition))
        {
            weight = 10;
            return true;
        }
    }
    return false;
}

void CreateChannel(std::vector<Channel*>& listOfChannel, std::vector<Node*>& listOfNode, std::vector<Text*>& listOfTextOfTypeChannel, std::vector<Text*>& listOfTextOfWeightChannel, sf::Vector2i mousePosition)
{
    int weightOfChannel = -1;
    int typeOfChannel = -1;
    /*
    do 
    {

    } while (!CollisonWithRectangle(weightOfChannel, listOfTextOfWeightChannel, mousePosition));*/
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
                    listOfChannel.push_back(new Channel(it1, it2, 0));
                }
                weHaveChannelBetweenNode = false;
            }
        }
    }
 
}

void DeleteSelectedNode(std::vector<Channel*>& listOfChannel, std::vector<Node*>& listOfNode)
{
    std::vector<Node*> listOfUnselectedNode;
    std::vector<Channel*> listOfSelectedChannel;
    for (auto it:listOfNode)
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
                    listOfSelectedChannel.push_back(itChannel);
                }
            }
        }
    }
    listOfNode = listOfUnselectedNode;
    /*listOfChannel.erase(std::remove_if(listOfChannel.begin(), listOfChannel.end(), [&](Channel* channel)
        {
            if (std::find(listOfSelectedChannel.begin(), listOfSelectedChannel.end(), channel) != listOfSelectedChannel.end())
            {
                return true;
            }
            return false;
        }
    ));*/

}