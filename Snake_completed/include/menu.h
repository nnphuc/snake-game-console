#ifndef MENU_H
#define MENU_H

#include "utility.h"
#include "menuitem.h"
#include "vector.h"
#include "graphic2d.h"

class Menu
{
public:
    Menu();
    void init();
    int selectedIndex() const;
    void setSelectedIndex(int selectedIndex);


    void add(MenuItem item);
    const Vector<MenuItem>& listItem() const;

    void setListItem(const Vector<MenuItem> &listItem);
    void onSelected();
    void show();
    void hide();

private:
    Vector<MenuItem> m_listItem;
    int m_selectedIndex;
    Graphic2D m_graphic;
    bool m_exit;
};

#endif // MENU_H
