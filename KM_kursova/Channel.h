#ifndef _CHANNEL_H_
#define _CHANNEL_H_

#define DUPLEX 0
#define HALF_DUPLEX 1

#include "Node.h"
#include <vector>

class Channel {
public:
    Channel() 
    {

    }
    Channel(Node* node1, Node* node2, int x, int t = 0)
    {
        color_ = sf::Color::Black;
        std::cout << "Constructor Channel between \n";
        node1_ = node1;
        node2_ = node2;
        weight_ = x;
        type_ = t;
        if (!font.loadFromFile("LemonMilk.otf"))
        {
            std::cout << "ERROR";
        }
        text.setFont(font);
        text.setCharacterSize(10);
        text.setFillColor(sf::Color::Black);
        text.setString(std::to_string(weight_));
        text.setPosition((node1_->get_position().x + node2_->get_position().x)/2, (node1_->get_position().y + node2_->get_position().y) / 2);
        
    }
    const unsigned int get_weight() const {
        return weight_;
    }
    const unsigned int get_type() const {
        return type_;
    }
    bool IsNodeInChannel(Node* node)
    {
        if (node->get_index() == node1_->get_index() || node->get_index() == node2_->get_index())
        {
            return true;
        }
        return false;
    }
    void set_Color(sf::Color color)
    {
        color_ = color;
    }
    /*
    function for display info when we select channel with mouse
    */
    sf::Vertex* get_line()
    {
        if (type_ == 0)
        {
            color_ = sf::Color(0, 0, 255);
        }
        else
        {
            color_ = sf::Color(128, 128, 128);
        }
        sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(node1_->get_position())),
            sf::Vertex(sf::Vector2f(node2_->get_position())),
        };
        line[0].color = color_;
        line[1].color = color_;
        return line;
        /*draw line between node1 node2 (we have position)*/
    }
    sf::Text get_text() const
    {
        return text;
    }
    const int get_node1_index() const
    {
        return node1_->get_index();
    }
    const int get_node2_index() const
    {
        return node2_->get_index();
    }
    bool WeHaveChannelBetween(Node* node1, Node* node2)
    {
        if (this->node1_->get_index() == node1->get_index() && this->node2_->get_index() == node2->get_index())
        {
            return true;
        }
        if (this->node2_->get_index() == node1->get_index() && this->node1_->get_index() == node2->get_index())
        {
            return true;
        }
        return false;
    }
    /*
    
    */
protected:

private:
    // for algorithm
    Node* node1_,* node2_;
    int weight_;
    unsigned int type_;

    //for send package
    int load;

    //for draw
    sf::Font font;
    sf::Text text;
    sf::Color color_;
};


#endif // !_CHANNEL_H_
