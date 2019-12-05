#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "Node.h"
#include "Channel.h"



class Algorithm {
public:
    Algorithm(std::vector<Node*>& listOfNode, std::vector<Channel*>& listOfChannel,int  indexOfEndNode, int indexOfStartNode)
    {
        numberOfGraph_ = listOfNode.size();
        startNodeIdex_ = indexOfStartNode;
        endNodeIndex_ = indexOfEndNode;
        if (startNodeIdex_ == -1 || endNodeIndex_ == -1)
        {
            std::cout << "ERROR\n";
            WeCanFindAlgorithm = false;
        }
        else
        {
            WeCanFindAlgorithm = true;
        }
    }
    std::vector<Node*> Start(std::vector<Node*>& listOfNode, std::vector<Channel*>& listOfChannel)
    {
        std::vector<Node*> result = {};

        if (WeCanFindAlgorithm)
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
                            listOfNode[i]->set_lenght(listOfNode[k]->get_lenght() + GetLenghtBetweenNodes(listOfNode, listOfChannel, k, i));
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

            do
            {
                result.push_back(listOfNode[k]);
                listOfNode[k]->set_colorNode(sf::Color::Red);
                k = listOfNode[k]->get_predecessor();
            } while (k >= 0);
        }
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
    bool WeCanFindAlgorithm;
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