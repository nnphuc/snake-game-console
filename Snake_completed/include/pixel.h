#ifndef PIXEL_H
#define PIXEL_H

#include "console.h"

class Pixel
{
public:
    Pixel();
    Pixel(int color);
    Pixel(int character,int textColor,int bgColor);

    int character() const;
    void setCharacter(int character);

    int textColor() const;
    void setTextColor(int textColor);

    int backgroundColor() const;
    void setBackgroundColor(int backgroundColor);

    bool operator==(const Pixel &other) const;
    bool operator!=(const Pixel &other) const;

    static const int DEFAULT_CHARACTER=' ';
    static const int DEFAULT_TEXT_COLOR=Console::WHITE;
    static const int DEFAULT_BACKGROUND_COLOR=Console::AQUA;
private:
    int m_character;
    int m_textColor;
    int m_backgroundColor;
};

#endif // PIXEL_H
