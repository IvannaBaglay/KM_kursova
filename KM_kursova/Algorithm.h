#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "Node.h"
#include "Channel.h"



class Algorithm {
public:
    Algorithm(std::vector<Node*>& listOfNode, std::vector<Channel*>& listOfChannel)
    {
        numberOfGraph = listOfNode.size();
        int currentIndex = 0;
        for (auto it : listOfNode)
        {
            if (it->get_isSelect())
            {
                if (startNodeIdex == -1)
                {
                    startNodeIdex = currentIndex;
                }
                else
                {
                    endNodeIndex = currentIndex;
                }

            }
            ++currentIndex;
        }
    }
    void Start(std::vector<Node*>& listOfNode, std::vector<Channel*>& listOfChannel)
    {
       
        listOfNode[startNodeIdex]->set_lenght(0);
        listOfNode[startNodeIdex]->set_label(permanent);
        int k = startNodeIdex;
        int min = -1;
        do
        {
            for (int i = 0; i < numberOfGraph; i++)
            {                            
                if (GetLenghtBetweenNodes(listOfNode, listOfChannel, k, i) != 0 && listOfNode[i]->get_label() == tentative)
                {
                    if (listOfNode[k]->get_lenght() + GetLenghtBetweenNodes(listOfNode, listOfChannel, k, i) < listOfNode[i]->get_lenght())
                    {
                        listOfNode[i]->set_predecessor(k);
                        listOfNode[i]->set_lenght(listOfNode[k]->get_lenght() + GetLenghtBetweenNodes(listOfNode, listOfChannel, k, i)) ;
                    }
                }
            }
            k = 0;
            min = INFINITY;
            for (int i = 0; i < numberOfGraph; i++)
            {
                if (listOfNode[i]->get_label() == tentative && listOfNode[i]->get_lenght() < min)
                {
                    min = listOfNode[i]->get_lenght();
                    k = i;
                }
            }
            listOfNode[k]->set_label(permanent);

        } while (k != endNodeIndex);
        do 
        {
            listOfNode[k]->set_colorNode(sf::Color::Red);
            k = listOfNode[k]->get_predecessor();
        } while (k >= 0);
    }
    int GetLenghtBetweenNodes(std::vector<Node*>& listOfNode, std::vector<Channel*>& listOfChannel, int indexNode1, int indexNode2)
    {
        for (auto it : listOfChannel)
        {
            if (it->WeHaveChannelBetween(listOfNode[indexNode1], listOfNode[indexNode2]))
            {
                return it->get_weight();
            }
        }
        return 0;
    }
protected:

    /*
    function for finding weight channel between two Node
    int FindWeight(Node1, Node2, vector<Node> vectorOfNode)
        {

        }
    */
private:    
    int numberOfGraph;
    int startNodeIdex = -1;
    int endNodeIndex = -1;
    /*vector of struct we fill in constructor from channel and node */
    /*
    or we can add all paramets from struct into Node and working with vector of Node
    struct {
    int predecessor;
    int lenght;
    enum (permanent, tentative) label;
    }
    
    */
};

#endif // !_ALGORITHM_H_