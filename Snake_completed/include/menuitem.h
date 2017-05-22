#ifndef MENUITEM_H
#define MENUITEM_H

#include "utility.h"
#include "graphic2d.h"

typedef void (*handle_func)(void *);

class MenuItem
{
public:
    MenuItem();
    const static int SPIN_BOX=0;
    const static int LIST=1;
    int type() const;
    void setType(int type);
    void show(int index,Graphic2D &g);

    int value() const;
    void setValue(int value);

    std::string info() const;
    void setInfo(const std::string &info);


    handle_func func() const;
    void setFunc(const handle_func &func);
    void setFunc(const handle_func &func,void *data);

    void onSelected();

    int minValue() const;
    void setMinValue(int minValue);

    int maxValue() const;
    void setMaxValue(int maxValue);

    void up();
    void down();

    void show(int index, int textColor, int bgColor, Graphic2D &g);
private:
    int m_type;
    int m_value;
    std::string m_info;
    handle_func m_func;
    int m_minValue;
    int m_maxValue;
    void *m_data;
};

#endif // MENUITEM_H
