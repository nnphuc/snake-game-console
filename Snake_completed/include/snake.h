#ifndef SNAKE_H
#define SNAKE_H

#include "list.h"
#include "point.h"
#include "direction.h"
#include "map.h"

class Snake
{
public:
    Snake();
    int size();

    Point nextHead();
    bool eat(const Point &p);
    bool move(Map &map);
    void drawInMap(Map &map);
    Point head();

    Direction direction() const;
    void setDirection(const Direction &direction);

private:
    List<Point> m_body;
    Direction m_direction;
    Direction m_lastMoveDirection;

};

#endif // SNAKE_H
