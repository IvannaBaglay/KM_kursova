#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>

#include "global_value.h"

static int index = 0;

class Node {
    enum enum_type { station, link };
public:
    Node()
    {

    }
    Node(sf::Vector2i positionOfMouse) 
    {
        positionX_ = positionOfMouse.x  ;
        positionY_ = positionOfMouse.y;  
        nodeCircle_.setRadius(radius_);
        nodeCircle_.setPosition(positionOfMouse.x, positionOfMouse.y);
        nodeCircle_.setFillColor(sf::Color::Black);
        isAble_ = true;    
        isSelected_ = false;
        index_ = index++;
    }
    bool IsAble()
    {
        return isAble_;
    }
    enum_type Type()
    {
        return type_;
    }
    void Draw(sf::RenderWindow& window)
    {
        window.draw(nodeCircle_);
    }
    const sf::CircleShape get_nodeCircle() const
    {
        return nodeCircle_;
    }
    const sf::Vector2i get_position() const
    {
        return sf::Vector2i(positionX_, positionY_);
    }
    void set_colorNode(sf::Color color) {
        nodeCircle_.setFillColor(color);
    }
    bool IsCollision(sf::Vector2i position)
    {
        if (sqrt((position.x - positionX_) * (position.x - positionX_) + (position.y - positionY_) * (position.y - positionY_)) <= 2 * radius_ + 1)
        {            
            return true;
        }
        return false;
    }
    void set_isSelected()
    {
        if (isSelected_)
        {
            nodeCircle_.setFillColor(sf::Color::Black);
        }
        else
        {
            nodeCircle_.setFillColor(sf::Color::Green);
            
        }
        isSelected_ = !isSelected_;
    }
    bool get_isSelect()
    {
        return isSelected_;
    }
    const int get_index() const
    {
        return index_;
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
    enum_type type_; 
    int positionX_;
    int positionY_;
    sf::CircleShape nodeCircle_;
    float radius_ = 10;
    bool isSelected_;

    /*value for algorithm*/
    int lenght_;
    bool isAble_; // change on enum
    int index_;
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
