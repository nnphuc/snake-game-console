#include "map.h"


Map::Map()
{

}

Map &Map::operator=(const Map &other)
{
    if(this==&other){
        return *this;
    }
    m_width=other.width();
    m_height=other.height();
    m_map.resize(m_height,vec_int1d(m_width));
    for(int y=0;y<height();y++){
        for(int x=0;x<width();x++){
            m_map[y][x]=other.m_map[y][x];
        }
    }
    return *this;
}

Map::Map(int width, int height)
{
    m_width=width;
    m_height=height;
    m_map.resize(height,vec_int1d(m_width));
}

void Map::load(const char map[GAME_HEIGHT][GAME_WIDTH+1])
{
    for(int y=0;y<height();y++){
        for(int x=0;x<width();x++){
            m_map[y][x]=map[y][x]==' '?Map::MAP_EMPTY:Map::MAP_WALL;
        }
    }
}

int Map::width() const
{
    return m_width;
}

void Map::setWidth(int width)
{
    m_width = width;
}

int Map::height() const
{
    return m_height;
}

void Map::setHeight(int height)
{
    m_height = height;
}

Map::vec_int1d &Map::operator[](int index)
{
    return m_map[index];
}

const Map::vec_int1d &Map::operator[](int index) const
{
    return m_map[index];
}

Point Map::food()
{
    srand(time(NULL));
    Vector<Point> a;
    for(int y=0;y<height();y++){
        for(int x=0;x<width();x++){
            if(m_map[y][x]==Map::MAP_EMPTY){
                a.push(Point(x,y));
            }
        }
    }
    Point f= a[rand()%a.size()];
    m_map[f.y()][f.x()]=Map::MAP_FOOD;
    return f;
}
