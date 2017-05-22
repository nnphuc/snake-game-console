#ifndef POINT_H
#define POINT_H

#include "direction.h"

class Point
{
public:
    Point();
    Point(const Point &other);
    Point(int x,int y);
    int x() const;
    void setX(int x);

    int y() const;
    void setY(int y);
    const Point &operator= (const Point &other);
    Point operator+(const Point &other);
    Point operator-(const Point &other);
    bool operator ==(const Point &other);

    void move(Direction direct);

private:
    int m_x;
    int m_y;

};

#endif // POINT_H
