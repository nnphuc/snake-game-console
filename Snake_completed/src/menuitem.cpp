#include "menuitem.h"

void DEFAULT_HANDLE(void *a){

}

MenuItem::MenuItem()
{
    m_value=1;
    m_minValue=1;
    m_maxValue=100;
    m_func=DEFAULT_HANDLE;
    m_data=NULL;
}



int MenuItem::type() const
{
    return m_type;
}

void MenuItem::setType(int type)
{
    m_type = type;
}

void MenuItem::show(int index,int textColor,int bgColor, Graphic2D &g)
{
    char text[100];

    if(m_type==SPIN_BOX){
        sprintf(text,"%-10s < %4d >",m_info.c_str(),m_value);
        g.writeJustify(1,index,textColor,bgColor,text);

    }else{
        g.writeJustify(1,index,textColor,bgColor,m_info.c_str());
    }

}

int MenuItem::value() const
{
    return m_value;
}

void MenuItem::setValue(int value)
{
    m_value = value;
}

std::string MenuItem::info() const
{
    return m_info;
}

void MenuItem::setInfo(const std::string &info)
{
    m_info = info;
}

handle_func MenuItem::func() const
{
    return m_func;
}

void MenuItem::setFunc(const handle_func &func)
{
    m_func = func;
}

void MenuItem::setFunc(const handle_func &func, void *data)
{
    m_func=func;
    m_data=data;
}

void MenuItem::onSelected()
{
    m_func(m_data);
}

int MenuItem::minValue() const
{
    return m_minValue;
}

void MenuItem::setMinValue(int minValue)
{
    m_minValue = minValue;
}

int MenuItem::maxValue() const
{
    return m_maxValue;
}

void MenuItem::setMaxValue(int maxValue)
{
    m_maxValue = maxValue;
}

void MenuItem::up()
{
    m_value++;
    if(m_value>m_maxValue){
        m_value=m_minValue;
    }
}

void MenuItem::down()
{
    m_value--;
    if(m_value<m_minValue){
        m_value=m_maxValue;
    }
}
