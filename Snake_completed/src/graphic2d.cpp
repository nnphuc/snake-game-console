#include "graphic2d.h"

Graphic2D::Graphic2D()
{
    m_top=0;
    m_left=0;
    m_width=DEFAULT_WIDTH;
    m_height=DEFAULT_HEIGHT;
    m_map.resize(m_height,Row(m_width));
    m_lastPaintedMap=m_map;
}

Graphic2D::Graphic2D(int width, int height)
{
    m_top=0;
    m_left=0;
    m_width=width;
    m_height=height;
    m_map.resize(m_height,Row(m_width));
    m_lastPaintedMap=m_map;
}

Graphic2D::Graphic2D(int left, int top, int width, int height)
{
    m_left=left;
    m_top=top;
    m_width=width;
    m_height=height;
    m_map.resize(m_height,Row(m_width));
    m_lastPaintedMap=m_map;
}

void Graphic2D::clear()
{
    m_map.resize(m_height,Row(m_width));
    m_lastPaintedMap=m_map;
}

int Graphic2D::left() const
{
    return m_left;
}

void Graphic2D::setLeft(int left)
{
    m_left = left;
}

void Graphic2D::paint()
{
    for(int y=0;y<m_height;y++){
        for(int x=0;x<m_width;x++){
            drawPixel(x,y,m_map[y][x]);
        }
    }
}

void Graphic2D::repaint()
{
    for(int y=0;y<m_height;y++){
        for(int x=0;x<m_width;x++){
            if(m_map[y][x]!=m_lastPaintedMap[y][x]){
                drawPixel(x,y,m_map[y][x]);
            }
        }
    }
}

void Graphic2D::drawPixel(int x, int y, const Pixel &pixel)
{
    m_console.gotoXY(x+m_left,y+m_top);
    m_console.setBackground(pixel.backgroundColor());
    m_console.setTextColor(pixel.textColor());
    m_console.write(pixel.character());
    m_lastPaintedMap[y][x]=pixel;
    m_map[y][x]=pixel;

}

Graphic2D::Map2D &Graphic2D::map()
{
    return m_map;
}

const Graphic2D::Map2D &Graphic2D::map() const
{
    return m_map;
}

void Graphic2D::setPixel(int x, int y, const Pixel &pixel)
{
    m_map[y][x]=pixel;
}

Pixel Graphic2D::getPixel(int x, int y) const
{
    return m_map[y][x];
}


int Graphic2D::top() const
{
    return m_top;
}

void Graphic2D::setTop(int top)
{
    m_top = top;
}

int Graphic2D::width() const
{
    return m_width;
}

void Graphic2D::setWidth(int width)
{
    m_width = width;
}

int Graphic2D::height() const
{
    return m_height;
}

void Graphic2D::setHeight(int height)
{
    m_height = height;
}

void Graphic2D::drawMap(const Map &map)
{
    for(int y=0;y<height();y++){
        for(int x=0;x<width();x++){
            m_map[y][x]=PIXEL[map[y][x]];
        }
    }
}

void Graphic2D::write(int x, int y, char ch)
{
    m_map[y][x].setCharacter(ch);
}

void Graphic2D::write(int x, int y, int textColor, int bgColor, char ch)
{
    m_map[y][x]=Pixel(ch,textColor,bgColor);
}

void Graphic2D::write(int x, int y, int textColor, char ch)
{
    m_map[y][x].setCharacter(ch);
    m_map[y][x].setTextColor(textColor);
}

void Graphic2D::write(int x, int y, int textColor, int bgColor, const char *str)
{
    int len=strlen(str);
    int line=y;
    for(int i=0;i<len;i++){
        int x_=x+i;
        if(x_>=width()){
            x_%=width();
            line++;
        }
        m_map[line][x_]=Pixel(str[i],textColor,bgColor);
    }
}

void Graphic2D::writeJustify(int x, int y, int textColor, int bgColor, const char *str)
{
    write(x,y,textColor,bgColor,str);
    int len=strlen(str);
    for(int i=len+x;i<width()-x;i++){
        m_map[y][i]=Pixel(' ',textColor,bgColor);
    }
}

void Graphic2D::writeCenter(int line, int textColor, int bgColor, const char *str)
{
    int len=strlen(str);
    int space=(width()-len-2)/2;
    for(int x=1;x<space;x++){
        write(x,line,textColor,bgColor,' ');
    }
    writeJustify(space,line,textColor,bgColor,str);
    for(int x=space+len;x<width()-1;x++){
        write(x,line,textColor,bgColor,' ');
    }
}



