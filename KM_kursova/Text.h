#ifndef _TEXT_H_
#define _TEXT_H_

#include "global_value.h"

class Text
{
public:
    Text(std::string string, float x, float y, bool isInCentre)
    {
        if (!font_.loadFromFile("LemonMilk.otf"))
        {
            std::cout << "ERROR\n";
        }
        positionX = x;
        positionY = y;
        text_.setFont(font_);
        text_.setString(string);
        text_.setCharacterSize(13);
        text_.setFillColor(sf::Color::Black);
        if (isInCentre)
        {
            text_.setPosition(positionX + lenghtOfRectangle / 2, positionY + weightOfRectangle / 2);
        }
        else
        {
            text_.setPosition(positionX, positionY);
        }
       rectangle.setOutlineThickness(1.f);
        rectangle.setOutlineColor(sf::Color::Black);
        rectangle.setSize(sf::Vector2f(lenghtOfRectangle, weightOfRectangle + weightOfRectangle / 2));
        rectangle.setFillColor(sf::Color(224, 224, 224));
        rectangle.setPosition(positionX, positionY);
        /*set color, text, rectangle*/
    }
    Text(std::string string, float x, float y, int sizeOfText, int weight, int lenght, sf::Color colorOfRegtangle, sf::Color ColorOfText)
    {
        if (!font_.loadFromFile("LemonMilk.otf"))
        {
            std::cout << "ERROR\n";
        }
        positionX = x;
        positionY = y;
        text_.setFont(font_);
        text_.setString(string);
        text_.setCharacterSize(24);
        text_.setFillColor(sf::Color::Black);
        text_.setPosition(positionX + lenghtOfRectangle / 2, positionY + weightOfRectangle / 2);
        rectangle.setOutlineThickness(1.f);
        rectangle.setOutlineColor(sf::Color::Black);
        rectangle.setSize(sf::Vector2f(lenghtOfRectangle, weightOfRectangle));
        rectangle.setFillColor(sf::Color(224, 224, 224));
        rectangle.setPosition(positionX, positionY);
        /*set color, text, rectangle*/
    }
    const sf::Text get_text() const
    {
        return text_;
    }
    const sf::RectangleShape get_rectangle() const
    {
        return rectangle;
    }
    bool IsCollision(sf::Vector2i& position)
    {
        if (positionX < position.x && positionX + lenghtOfRectangle > position.x
            && positionY < position.y && positionY + weightOfRectangle > position.y)
        {
            return true;
        }
        return false;
    }
    int get_value() const
    {
        std::string value = text_.getString();
        if (value == "duplex" )
        {
            return 0;
        }
        else if (value == "half-duplex")
        {
            return 1;
        }
        else if (value == "random")
        {
            return 5;
        }
        else
        {
            return atoi(value.c_str());
        }
    }
    /*return text*/
    /*return rectangle for draw in main*/

protected:

private:
    sf::Font font_;
    sf::Text text_;
    sf::RectangleShape rectangle;
    float weightOfRectangle = 50.0;
    float lenghtOfRectangle = 100.0;
    float positionX;
    float positionY;

    /*text and rectangle*/
};

#endif // !_TEXT_H_
