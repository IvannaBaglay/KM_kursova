#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>

#include "global_value.h"

class Node {
    enum enum_type { station, link };
public:
    Node(sf::Vector2i positionOfMouse) 
    {
        
        std::cout << "X:" << positionOfMouse.x << std::endl;
        std::cout << "Y:" << positionOfMouse.y << std::endl;
        positionX = positionOfMouse.x  ;
        positionY = positionOfMouse.y;
        std::cout << "Xs:" << positionX << std::endl;
        std::cout << "Ys:" << positionY << std::endl;
        nodeCircle.setRadius(10.f);
        nodeCircle.setPosition(positionOfMouse.x, positionOfMouse.y);
        nodeCircle.setFillColor(sf::Color::Black);
        isAble = true;      
    }
    bool IsAble()
    {
        return isAble;
    }
    enum_type Type()
    {
        return type;
    }
    void Draw(sf::RenderWindow& window)
    {
        window.draw(nodeCircle);
    }
    const sf::CircleShape get_nodeCircle() const
    {
        return nodeCircle;
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
    enum_type type; 
    int positionX;
    int positionY;
    sf::CircleShape nodeCircle;

    /*value for algorithm*/
    int lenght;
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
