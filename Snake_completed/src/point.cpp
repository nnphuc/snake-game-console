#include "Point.h"

Point::Point()
{
    m_x=m_y=0;
}

Point::Point(const Point &other)
{
    if(this==&other){
        return;
    }
    m_x=other.x();
    m_y=other.y();
}

Point::Point(int x, int y)
{
    m_x=x;
    m_y=y;
}

int Point::x() const
{
    return m_x;
}

void Point::setX(int x)
{
    m_x = x;
}

int Point::y() const
{
    return m_y;
}

void Point::setY(int y)
{
    m_y = y;
}

const Point &Point::operator=(const Point &other)
{
    if(this!=&other){
        m_x=other.x();
        m_y=other.y();
    }
    return *this;
}

Point Point::operator+(const Point &other)
{
    return Point(x()+other.x(),y()+other.y());
}

Point Point::operator-(const Point &other)
{
    return Point(x()-other.x(),y()-other.y());
}

bool Point::operator ==(const Point &other)
{
    return x()==other.x() && y()==other.y();
}

void Point::move(Direction direct)
{
    switch (direct) {
    case Direction::UP:
        m_y--;
        break;
    case Direction::DOWN:
        m_y++;
        break;
    case Direction::LEFT:
        m_x--;
        break;
    case Direction::RIGHT:
        m_x++;
        break;
    default:
        break;
    }
}
