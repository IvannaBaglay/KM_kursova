#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>

#include "global_value.h"

class Node {
    enum enum_type { station, link };
public:
    Node(sf::Vector2i positionOfMouse) 
    {
        positionX = positionOfMouse.x  ;
        positionY = positionOfMouse.y;  
        nodeCircle.setRadius(radius);
        nodeCircle.setPosition(positionOfMouse.x, positionOfMouse.y);
        nodeCircle.setFillColor(sf::Color::Black);
        isAble = true;    
        isSelected = false;
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
    const sf::Vector2i get_position() const
    {
        return sf::Vector2i(positionX, positionY);
    }
    void set_colorNode(sf::Color color) {
        nodeCircle.setFillColor(color);
    }
    bool IsCollision(sf::Vector2i position)
    {
        if (sqrt((position.x - positionX) * (position.x - positionX) + (position.y - positionY) * (position.y - positionY)) <= 2 * radius + 1)
        {            
            return true;
        }
        return false;
    }
    void set_isSelected()
    {
        if (isSelected)
        {
            nodeCircle.setFillColor(sf::Color::Black);
        }
        else
        {
            nodeCircle.setFillColor(sf::Color::Green);
            
        }
        isSelected = !isSelected;
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
    float radius = 10;
    bool isSelected;

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
