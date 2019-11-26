#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "Node.h"
#include "Channel.h"



class Algorithm {
public:
    Algorithm()
    {
        /*CreateTable()*/
    }
    void Start();
protected:
    void CreateTable()
    {

    }

    /*
    function for finding weight channel between two Node
    int FindWeight(Node1, Node2, vector<Node> vectorOfNode)
        {

        }
    */
private:
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