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
private:
    /*Matrix of Node and Channel (Node*Node) how node are connected*/
    /*struct for result
    struct {
    int predecessor;
    int lenght;
    enum (permanent, tentative) label;
    }
    
    */
};

#endif // !_ALGORITHM_H_