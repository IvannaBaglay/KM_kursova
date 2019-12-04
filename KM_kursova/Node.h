#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>


#include "global_value.h"
#include "Text.h"

#define INFINITY 100000

static int index = 0;

class Node {
public:
    Node()
    {
        index_ = -1;
    }
    Node(sf::Vector2i positionOfMouse) 
    {
        nodeCircle_.setRadius(radius_);
        positionX_ = positionOfMouse.x + radius_;
        positionY_ = positionOfMouse.y + radius_;       
        nodeCircle_.setPosition(positionOfMouse.x, positionOfMouse.y);
        nodeCircle_.setFillColor(sf::Color::Black);
        isSelected_ = false;
        isStation_ = false;
        haveAddedInformation_ = false;
        index_ = index++;   
        if (!font_.loadFromFile("LemonMilk.otf"))
        {
            std::cout << "ERROR";
        }
        text_.setFont(font_);
        text_.setCharacterSize(18);
        text_.setFillColor(sf::Color(225,0,0));
        text_.setString(std::to_string(index_));
        text_.setPosition(positionOfMouse.x, positionOfMouse.y);

        predecessor_ = -1;
        lenght_ = INFINITY;
        label_ = tentative;

    }
    void Draw(sf::RenderWindow& window)
    {
        window.draw(nodeCircle_);
        window.draw(text_);
    }
    const sf::CircleShape get_nodeCircle() const
    {
        return nodeCircle_;
    }
    const sf::Text get_text() const
    {
        return text_;
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
        if (sqrt((position.x - positionX_) * (position.x - positionX_) + (position.y - positionY_) * (position.y - positionY_)) <= 2*radius_)
        {            
            return true;
        }
        return false;
    }
    void set_isSelected()
    {
        isSelected_ = !isSelected_;
        if (isSelected_)
        {
            nodeCircle_.setFillColor(sf::Color::Green);
        }
        else
        {
            if (isStation_)
            {
                nodeCircle_.setFillColor(sf::Color::Blue);
            }
            else
            {
                nodeCircle_.setFillColor(sf::Color::Black);
            }
            
        }
        
    }
    void set_isStation(bool state)
    {
        isStation_ = state;
    }
    const bool get_isStation() const
    {
        return isStation_;
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
    sf::Text get_addedInformation()
    {
        sf::Text TextAddedInformation;
        std::string string("200");
        TextAddedInformation.setFont(font_);
        TextAddedInformation.setCharacterSize(18);
        TextAddedInformation.setFillColor(sf::Color::Black);
        TextAddedInformation.setPosition(positionX_, positionY_);
        if (haveAddedInformation_)
        {
            for (auto it : information_)
            {
                string = it.first + "\t" + it.second + "\n";
            }
            if (!font_.loadFromFile("LemonMilk.otf"))
            {
                std::cout << "ERROR";
            }           
                     
        }
        TextAddedInformation.setString(string);
        std::cout << string;
        std::cout << "\n\n\n";
        return TextAddedInformation;
    }
    void set_haveAddedInformation(bool flag)
    {
        haveAddedInformation_ = false;
    }
    void set_label(enumLabel label)
    {
        label_ = label;
    }
    void set_lenght(int lenght)
    {
        lenght_ = lenght;
    }
    enumLabel get_label()
    {
        return label_;
    }
    const bool get_haveAddedInformation() const
    {
        return haveAddedInformation_;
    }
    const int get_lenght() const
    {
        return lenght_;
    }
    void set_predecessor(int predecessor)
    {
        predecessor_ = predecessor;
    }
    const int get_predecessor() const
    {
        return predecessor_;
    }
    void AddInformation(std::pair<std::string, std::string> information)
    {
        if (std::find(information_.begin(), information_.end(), information) == information_.end())
        {
            information_.push_back(information);
        }
    }
    void Output()
    {
        for (auto it : information_)
        {
            std::cout << it.first << "\t" << it.second << std::endl;
        }
    }
private:

protected:
    /*value for draw*/  
    int positionX_;
    int positionY_;
    sf::CircleShape nodeCircle_;
    float radius_ = 10;
    bool isSelected_;
    sf::Text text_;
    sf::Font font_;
    int index_;
    bool isStation_;

    /*Information about send*/
    bool haveAddedInformation_;
    std::vector<std::pair<std::string, std::string>> information_;
    //std::vector<Text*> information_;


    /*value for algorithm*/
    int predecessor_;
    int lenght_;
    enumLabel label_;


    
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
