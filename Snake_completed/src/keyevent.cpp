#include "keyevent.h"

KeyEvent::KeyEvent()
{

}

KeyEvent::KeyEvent(int code, uint64_t time)
{
    m_keyCode=code;
    m_time=time;
}

int KeyEvent::keyCode() const
{
    return m_keyCode;
}

void KeyEvent::setKeyCode(int keyCode)
{
    m_keyCode = keyCode;
}

uint64_t KeyEvent::time() const
{
    return m_time;
}

void KeyEvent::setTime(const uint64_t &value)
{
    m_time = value;
}
