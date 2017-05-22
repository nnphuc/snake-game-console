#include "snake.h"

Snake::Snake()
{
    m_body.pushBack(Point(1,0));
    m_body.pushBack(Point(0,0));
    m_direction=Direction::RIGHT;
    m_lastMoveDirection=Direction::RIGHT;
}

int Snake::size()
{
    return m_body.size();
}

Point Snake::nextHead()
{
    Point head=m_body.front();
    head.move(m_direction);
    return head;
}

bool Snake::eat(const Point &p)
{
    Point head=nextHead();
    if(head==p){
        return true;
    }
    return false;
}

bool Snake::move( Map &map)
{
    m_lastMoveDirection=m_direction;
    Point next=nextHead();
    if(next.y()>=map.height() || next.y()<0 || next.x()>=map.width() || next.x()<0){
        return false;
    }
    Point lastPop=m_body.back();
    int mapinfo=map[next.y()][next.x()];
    if(mapinfo==Map::MAP_FOOD){

        m_body.pushFront(next);
        return true;
    }else if(mapinfo==Map::MAP_EMPTY){
        map[lastPop.y()][lastPop.x()]=Map::MAP_EMPTY;
        map[m_body.front().y()][m_body.front().x()]=Map::SNAKE_BODY;
        m_body.pushFront(next);
        map[next.y()][next.x()]=Map::SNAKE_HEAD;
        m_body.popBack();
        return true;
    }else if(mapinfo==Map::SNAKE_BODY || mapinfo==Map::SNAKE_HEAD){
        return false;
    }else if(mapinfo==Map::MAP_WALL){
        return false;
    }else{
        return false;
    }
}

void Snake::drawInMap(Map &map)
{
    for(int y=0;y<map.width();y++){
        for(int x=0;x<map.height();x++){
            if(map[y][x]==Map::SNAKE_BODY || map[y][x]==Map::SNAKE_HEAD){
                map[y][x]=Map::MAP_EMPTY;
            }
        }
    }
    ListNode<Point> * head=m_body.head();
    map[head->data().y()][head->data().x()]=Map::SNAKE_HEAD;
    head=head->next();
    while(head!=NULL){
        map[head->data().y()][head->data().x()]=Map::SNAKE_BODY;
        head=head->next();
    }
}

Point Snake::head()
{
    return m_body.front();
}

Direction Snake::direction() const
{
    return m_direction;
}

void Snake::setDirection(const Direction &direction)
{
    if(m_lastMoveDirection+direction!=5){
        m_direction = direction;
    }
}

