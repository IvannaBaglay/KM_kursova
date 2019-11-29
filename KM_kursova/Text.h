#ifndef _TEXT_H_
#define _TEXT_H_

#include "global_value.h"

class Text
{
public:
    Text(std::string string)
    {
        text.setString(string);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Black);
        rectangle.setSize(sf::Vector2f(100.f, 50.f));
        rectangle.setFillColor(sf::Color(57, 44, 61));
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
    sf::Text text;
    sf::RectangleShape rectangle;
    /*text and rectangle*/
};

#endif // !_TEXT_H_
