#ifndef KEYEVENT_H
#define KEYEVENT_H

#include "utility.h"
#include "KeyCode.h"

class KeyEvent{
public:
    KeyEvent();
    KeyEvent(int code,uint64_t time);
    int keyCode() const;
    void setKeyCode(int keyCode);

    uint64_t time() const;
    void setTime(const uint64_t &value);

private:
    int m_keyCode;
    uint64_t m_time;
};


#endif // KEYEVENT_H
