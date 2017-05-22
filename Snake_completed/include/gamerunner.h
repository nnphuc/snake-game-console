#ifndef GAMERUNNER_H
#define GAMERUNNER_H

#include "graphic2d.h"
#include "map.h"
#include "list.h"
#include "vector.h"
#include "snake.h"
#include "point.h"
#include "keyevent.h"

class GameRunner
{
public:
    GameRunner();
    int level() const;
    void setLevel(int level);

    void setMap(int mapIndex);

    int score() const;
    void setScore(int score);


    bool isRunning() const;
    void setIsRunning(bool isRunning);

    bool cancel() const;
    void setCancel(bool cancel);

    void run();

private:
    void input();
    void gameRunning();
    Graphic2D m_graphicGame;
    Graphic2D m_scoreBoard;
    List<KeyEvent> m_keyQueue;
    Snake m_snake;
    Map m_map;
    Point m_food;
    int m_level;
    int m_score;
    bool m_isRunning;
    bool m_cancel;

    std::mutex m_lockInputReader;
    std::thread m_inputThread;
    std::thread m_gameRunningThread;
};

#endif // GAMERUNNER_H
