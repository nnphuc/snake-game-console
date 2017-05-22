#include <iostream>
#include "list.h"
#include "pixel.h"
#include "graphic2d.h"
#include "snake.h"
#include "gamerunner.h"
#include "menu.h"
using namespace std;

int main(int argc, char *argv[])
{
    Menu menu;
    menu.init();
    MenuItem it1,it2,it3,it4;
    it1.setType(MenuItem::LIST);
    it1.setInfo("run");
    it1.setFunc([](void *menu){
        Menu *m=(Menu *)menu;
        GameRunner game;

        game.setLevel(m->listItem()[1].value());
        game.setMap(m->listItem()[2].value());
        game.run();
        getch();

        m->init();

    },&menu);
    menu.add(it1);


    it2.setType(MenuItem::SPIN_BOX);
    it2.setInfo("level");
    it2.setValue(3);
    it2.setMaxValue(5);
    menu.add(it2);

    it3.setType(MenuItem::SPIN_BOX);
    it3.setInfo("map");
    it3.setMaxValue(4);
    menu.add(it3);

    it4.setType(MenuItem::LIST);
    it4.setInfo("exit");
    it4.setFunc([](void *menu){
        Menu *m=(Menu *)menu;
        m->hide();
    },&menu);
    menu.add(it4);
    menu.onSelected();

    return 0;
}
