#include "pixel.h"

Pixel::Pixel()
{
    m_character=DEFAULT_CHARACTER;
    m_textColor=DEFAULT_TEXT_COLOR;
    m_backgroundColor=DEFAULT_BACKGROUND_COLOR;
}

Pixel::Pixel(int bgcolor):Pixel()
{
    m_backgroundColor=bgcolor;
}

Pixel::Pixel(int character, int textColor, int bgColor)
{
    m_character=character;
    m_textColor=textColor;
    m_backgroundColor=bgColor;
}

int Pixel::character() const
{
    return m_character;
}

void Pixel::setCharacter(int character)
{
    m_character = character;
}

int Pixel::textColor() const
{
    return m_textColor;
}

void Pixel::setTextColor(int textColor)
{
    m_textColor = textColor;
}

int Pixel::backgroundColor() const
{
    return m_backgroundColor;
}

void Pixel::setBackgroundColor(int backgroundColor)
{
    m_backgroundColor = backgroundColor;
}

bool Pixel::operator==(const Pixel &other) const
{
    return m_character==other.character() &&
           m_textColor==other.textColor() &&
           m_backgroundColor==other.backgroundColor();
}

bool Pixel::operator!=(const Pixel &other) const
{
    return !((*this)==other);
}
