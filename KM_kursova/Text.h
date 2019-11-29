#ifndef _TEXT_H_
#define _TEXT_H_

#include "global_value.h"

class Text
{
public:
    Text(std::string string, float x, float y)
    {
        if (!font.loadFromFile("LemonMilk.otf"))
        {
            std::cout << "ERROR\n";
        }
        text.setFont(font);
        text.setString(string);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Black);
        text.setPosition(x + lenghtOfRectangle / 2, y + weightOfRectangle / 2);
        rectangle.setOutlineThickness(1.f);
        rectangle.setOutlineColor(sf::Color::Black);
        rectangle.setSize(sf::Vector2f(lenghtOfRectangle, weightOfRectangle));
        rectangle.setFillColor(sf::Color(224, 224, 224));
        rectangle.setPosition(x, y);        
        /*set color, text, rectangle*/
    }
    const sf::Text get_text() const
    {
        return text;
    }
    const sf::RectangleShape get_rectangle() const
    {
        return rectangle;
    }
    /*return text*/
    /*return rectangle for draw in main*/

protected:

private:
    sf::Font font;
    sf::Text text;
    sf::RectangleShape rectangle;
    float weightOfRectangle = 50.0;
    float lenghtOfRectangle = 100.0;
    /*text and rectangle*/
};

#endif // !_TEXT_H_
