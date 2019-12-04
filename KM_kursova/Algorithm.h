#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "Node.h"
#include "Channel.h"



class Algorithm {
public:
    Algorithm(std::vector<Node*>& listOfNode, std::vector<Channel*>& listOfChannel)
    {
        numberOfGraph_ = listOfNode.size();
        int currentIndex = 0;
        for (auto it : listOfNode)
        {
            if (it->get_isSelect())
            {
                if (startNodeIdex_ == -1)
                {
                    startNodeIdex_ = currentIndex;
                }
                else
                {
                    endNodeIndex_ = currentIndex;
                }

            }
            ++currentIndex;
        }
    }
    std::vector<Node*> Start(std::vector<Node*>& listOfNode, std::vector<Channel*>& listOfChannel)
    {
       
        listOfNode[startNodeIdex_]->set_lenght(0);
        listOfNode[startNodeIdex_]->set_label(permanent);
        int k = startNodeIdex_;
        int min = -1;
        do
        {
            for (int i = 0; i < numberOfGraph_; i++)
            {                            
                if (GetLenghtBetweenNodes(listOfNode, listOfChannel, k, i) != 0 && listOfNode[i]->get_label() == tentative)
                {
                    if (listOfNode[k]->get_lenght() + GetLenghtBetweenNodes(listOfNode, listOfChannel, k, i) < listOfNode[i]->get_lenght())
                    {
                        listOfNode[i]->set_predecessor(k);
                        listOfNode[i]->set_lenght(listOfNode[k]->get_lenght() + GetLenghtBetweenNodes(listOfNode, listOfChannel, k, i)) ;
                        /*Added package in channel*/
                    }
                }
            }
            k = 0;
            min = INFINITY;
            for (int i = 0; i < numberOfGraph_; i++)
            {
                if (listOfNode[i]->get_label() == tentative && listOfNode[i]->get_lenght() < min)
                {
                    min = listOfNode[i]->get_lenght();
                    k = i;
                }
            }
            listOfNode[k]->set_label(permanent);

        } while (k != endNodeIndex_);
        std::vector<Node*> result = {};
        do 
        {
            result.push_back(listOfNode[k]);
            listOfNode[k]->set_colorNode(sf::Color::Red);
            k = listOfNode[k]->get_predecessor();
        } while (k >= 0);
        return result;
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
    const int get_endNodeIndex() const
    {
        return endNodeIndex_;
    }
protected:

    /*
    function for finding weight channel between two Node
    int FindWeight(Node1, Node2, vector<Node> vectorOfNode)
        {

        }
    */
private:    
    int numberOfGraph_;
    int startNodeIdex_ = -1;
    int endNodeIndex_ = -1;
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