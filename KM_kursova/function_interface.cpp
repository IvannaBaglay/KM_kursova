#include "function_interface.h"
#include "Node.h"

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
void CreateChannel(std::vector<Channel*>& listOfChannel, std::vector<Node*>& listOfNode) 
{
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
                    listOfChannel.push_back(new Channel(it1, it2));
                }
                weHaveChannelBetweenNode = false;
            }
        }
    }
 
}