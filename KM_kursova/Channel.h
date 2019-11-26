#ifndef _CHANNEL_H_
#define _CHANNEL_H_

#define DUPLEX 0
#define HALF_DUPLEX 1

#include "Node.h"

class Channel {
public:
    const unsigned int get_weight() const {
        return weight;
    }
    const unsigned int get_type() const {
        return type;
    }
    /*
    function for display info when we select channel with mouse
    */
    void Draw() 
    {
        /*draw line between node1 node2 (we have position)*/
    }
    /*
    
    */
protected:

private:
    Node node1, node2;
    int weight;
    unsigned int type;
};


#endif // !_CHANNEL_H_
