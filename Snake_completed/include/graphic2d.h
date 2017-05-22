#ifndef GRAPHIC2D_H
#define GRAPHIC2D_H

#include "vector.h"
#include "pixel.h"
#include "console.h"
#include "map.h"

class Graphic2D
{
public:
    typedef Vector<Pixel> Row;
    typedef Vector<Row> Map2D;
    Graphic2D();
    Graphic2D(int width,int height);
    Graphic2D(int left,int top,int width,int height);

    void clear();

    int left() const;
    void setLeft(int left);

    void paint();
    void repaint();

    void drawPixel(int x,int y,const Pixel &pixel);
    Map2D & map();
    const Map2D & map() const;

    void setPixel(int x,int y,const Pixel &pixel);
    Pixel getPixel(int x,int y) const;

    int top() const;
    void setTop(int top);

    int width() const;
    void setWidth(int width);

    int height() const;
    void setHeight(int height);
    void drawMap(const Map &map);
    void write(int x,int y,char ch);
    void write(int x,int y,int textColor,int bgColor,char ch);
    void write(int x,int y,int textColor,char ch);

    void write(int x,int y,int textColor,int bgColor,const char *str);
    void writeJustify(int x,int y,int textColor,int bgColor,const char *str);
    void writeCenter(int line,int textColor,int bgColor,const char *str);

    static const int DEFAULT_WIDTH=40;
    static const int DEFAULT_HEIGHT=15;

private:
    int m_left;
    int m_top;
    int m_width;
    int m_height;

    Console m_console;
    Map2D m_map;
    Map2D m_lastPaintedMap;

};

#endif // GRAPHIC2D_H
