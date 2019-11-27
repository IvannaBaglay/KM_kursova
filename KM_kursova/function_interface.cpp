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
