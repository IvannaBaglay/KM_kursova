#ifndef _NODE_H_
#define _NODE_H_

class Node {
public:
    bool IsAble()
    {
        return isAble;
    }
    bool IsStation()
    {
        return isStation;
    }
    /*
    add function for write weight from this node to another node
    void SetLenght()
    {

    }
    */
private:

protected:
    /*value for draw*/

    bool isStation; // maybe change on enum
    int lenght;

    /*value for algorithm*/
    int positionX;
    int positionY;
    bool isAble; // change on enum
    /*
    struct {
    int predecessor;
    int lenght;
    enum (permanent, tentative) label;
    }
    
    
    */
};

#endif // !_NODE_H_
#pragma once
