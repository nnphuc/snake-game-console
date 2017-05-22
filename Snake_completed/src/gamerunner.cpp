#include "gamerunner.h"

GameRunner::GameRunner()
{

    Console console;
    console.clear();

    console.setTitle("Game Snake");

    m_graphicGame=Graphic2D(1,1,GAME_WIDTH,GAME_HEIGHT);
    m_scoreBoard=Graphic2D(GAME_WIDTH+5,1,30,10);


    m_map=Map(m_graphicGame.width(),m_graphicGame.height());
    m_scoreBoard.paint();
    m_graphicGame.paint();
    m_isRunning=true;
    m_cancel=false;
    m_level=3;
    m_score=0;
}

int GameRunner::level() const
{
    return m_level;
}

void GameRunner::setLevel(int level)
{
    m_level = level;
}

void GameRunner::setMap(int mapIndex)
{
    m_map.load(DEFAULT_MAP[mapIndex-1]);
}

int GameRunner::score() const
{
    return m_score;
}

void GameRunner::setScore(int score)
{
    m_score = score;
}

bool GameRunner::isRunning() const
{
    return m_isRunning;
}

void GameRunner::setIsRunning(bool isRunning)
{
    m_isRunning = isRunning;
}

void GameRunner::input()
{
    while(!m_cancel){
        Sleep(5);
        if(kbhit()){
            m_lockInputReader.lock();
            int key=getch();
            m_keyQueue.pushBack(KeyEvent(key,now()));
            m_lockInputReader.unlock();
        }
    }

}

void GameRunner::gameRunning()
{
    uint64_t lastMoveTime=now();
    m_food=m_map.food();
    m_graphicGame.drawMap(m_map);
    m_graphicGame.repaint();
    char text[100];
    sprintf(text,"Level: %5d",m_level);
    m_scoreBoard.writeJustify(1,1,Console::WHITE,Console::GRAY,text);
    sprintf(text,"Score: %5d",m_score);
    m_scoreBoard.writeJustify(1,2,Console::WHITE,Console::GRAY,text);
    m_scoreBoard.repaint();
    while(!m_cancel){
        if(m_keyQueue.size()){
            m_lockInputReader.lock();
            int key=-1;
            while(m_keyQueue.size() && m_keyQueue.front().time()<now()){
                key=m_keyQueue.front().keyCode();
                m_keyQueue.popFront();
            }
            m_lockInputReader.unlock();
            switch(key){
                case KEY_UP:
                    m_snake.setDirection(Direction::UP);
                    break;
                case KEY_DOWN:
                    m_snake.setDirection(Direction::DOWN);
                    break;
                case KEY_LEFT:
                    m_snake.setDirection(Direction::LEFT);
                    break;
                case KEY_RIGHT:
                    m_snake.setDirection(Direction::RIGHT);
                    break;
                case KEY_P:
                case KEY_SPACE:{
                    m_isRunning=!m_isRunning;
                    char text[100];
                    if(m_isRunning){
                        strcpy(text,"Running");
                    }else{
                        strcpy(text,"Paused!");
                    }
                    m_scoreBoard.writeCenter(4,Console::WHITE,Console::GRAY,text);
                    m_scoreBoard.repaint();
                    break;
                case KEY_ESC:
                    m_isRunning=false;
                    m_cancel=true;
                    break;
                }
            }
        }
        // handle move
        if(m_isRunning){
            m_snake.drawInMap(m_map);
            m_graphicGame.repaint();
            Sleep(5);
            if(now()-lastMoveTime>(20ULL-3*m_level)*3e7){
                sprintf(text,"Position: (%2d,%2d)",m_snake.head().x(),m_snake.head().y());
                m_scoreBoard.writeJustify(1,3,Console::WHITE,Console::GRAY,text);
                m_scoreBoard.repaint();
                lastMoveTime=now();
                if(m_snake.eat(m_food)){
                    m_food=m_map.food();
                    m_score+=m_level;

                    sprintf(text,"Score: %5d",m_score);
                    m_scoreBoard.writeJustify(1,2,Console::WHITE,Console::GRAY,text);
                    m_scoreBoard.repaint();
                }
                if(!m_snake.move(m_map)){
                    m_cancel=true;
                }
                m_snake.drawInMap(m_map);
                m_graphicGame.drawMap(m_map);
                m_graphicGame.repaint();

            }
        }else{

        }
    }


}

bool GameRunner::cancel() const
{
    return m_cancel;
}

void GameRunner::setCancel(bool cancel)
{
    m_cancel = cancel;
}

void GameRunner::run()
{
    m_inputThread=std::thread(&GameRunner::input,this);
    m_gameRunningThread=std::thread(&GameRunner::gameRunning,this);
    m_inputThread.join();
    m_gameRunningThread.join();
}
