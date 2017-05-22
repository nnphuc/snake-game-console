#ifndef MAP_H
#define MAP_H

#include "vector.h"
#include "pixel.h"
#include "point.h"
#include "defaultmap.h"


const Pixel PIXEL_MAP_EMPTY(Console::AQUA);
const Pixel PIXEL_MAP_WALL(Console::LIGHT_GRAY);
const Pixel PIXEL_SNAKE_HEAD(Console::RED);
const Pixel PIXEL_SNAKE_BODY(Console::YELLOW);
const Pixel PIXEL_MAP_FOOD('*',Console::LIGHT_GREEN,Console::AQUA);

const Pixel PIXEL[5]={
    PIXEL_MAP_EMPTY,
    PIXEL_SNAKE_HEAD,
    PIXEL_SNAKE_BODY,
    PIXEL_MAP_WALL,
    PIXEL_MAP_FOOD
};

class Map
{
public:
    typedef Vector<int> vec_int1d;
    typedef Vector<vec_int1d> vec_int2d;

    Map();
    Map & operator=(const Map &other);
    Map(int width,int height);

    void load(const char map[GAME_HEIGHT][GAME_WIDTH+1]);

    int width() const;
    void setWidth(int width);

    int height() const;
    void setHeight(int height);

    vec_int1d & operator[](int index);
    const vec_int1d & operator[](int index)const;
    Point food();

    static const int MAP_EMPTY=0;
    static const int SNAKE_HEAD=1;
    static const int SNAKE_BODY=2;
    static const int MAP_WALL=3;
    static const int MAP_FOOD=4;


private:
    int m_width;
    int m_height;

    vec_int2d m_map;
};


#endif // MAP_H
