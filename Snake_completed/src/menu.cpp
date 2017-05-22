#include "menu.h"

Menu::Menu()
{

}

void Menu::init()
{
    Console console;
    console.setTitle("Menu");
    console.clear();
    m_selectedIndex=0;
    m_graphic=Graphic2D(1,1,30,15);
    m_graphic.paint();
    m_exit=false;
}



int Menu::selectedIndex() const
{
    return m_selectedIndex;
}

void Menu::setSelectedIndex(int selectedIndex)
{
    m_selectedIndex = selectedIndex;
}

void Menu::add(MenuItem item)
{
    m_listItem.push(item);
}



const Vector<MenuItem>& Menu::listItem() const
{
    return m_listItem;
}

void Menu::setListItem(const Vector<MenuItem> &listItem)
{
    m_listItem = listItem;
}

void Menu::onSelected()
{


    while(!m_exit){
        int key=-1;
        Sleep(10);
        show();
        if(kbhit()){
            int key=getch();
            switch (key) {
            case KEY_UP:
                m_selectedIndex--;
                if(m_selectedIndex<0){
                    m_selectedIndex=m_listItem.size()-1;
                }
                break;
            case KEY_DOWN:
                m_selectedIndex++;
                if(m_selectedIndex>=m_listItem.size()){
                    m_selectedIndex=0;
                }
                break;
            case KEY_LEFT:
                if(m_listItem[m_selectedIndex].type()==MenuItem::SPIN_BOX){
                    m_listItem[m_selectedIndex].down();
                }
                break;
            case KEY_RIGHT:
                if(m_listItem[m_selectedIndex].type()==MenuItem::SPIN_BOX){
                    m_listItem[m_selectedIndex].up();
                }
                break;
            case KEY_ENTER:
            case KEY_SPACE:

                if(m_listItem[m_selectedIndex].type()==MenuItem::LIST){
                    m_listItem[m_selectedIndex].onSelected();
                }

            default:
                break;
            }
        }


    }
}

void Menu::show()
{
    for(int i=0;i<m_listItem.size();i++){
        if(i==m_selectedIndex){
            m_listItem[i].show(i+1,Console::GREEN,Console::GRAY,m_graphic);
        }else{
             m_listItem[i].show(i+1,Console::WHITE,Console::GRAY,m_graphic);
        }
    }
    m_graphic.repaint();
}

void Menu::hide()
{
    m_exit=true;
}
