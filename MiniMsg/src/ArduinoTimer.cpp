#include "ArduinoTimer.h"
#include "Arduino.h"
#include "ArduinoDebug.h"

using namespace MiniMsg;

ArduinoTimer* ArduinoTimer::s_instance;

void ArduinoTimer::create_instance()
{
    static ArduinoTimer c_instance;
    s_instance = &c_instance;
}

ArduinoTimer& ArduinoTimer::get_instance()
{
    ASSERT(s_instance != nullptr, "tried to get NULL instance of ArduinoTimer");
    return *s_instance;
}

ArduinoTimer::ArduinoTimer()
{
   m_elapsed = 0;
   m_offset = 0;
}

uint64_t ArduinoTimer::time_elapsed()
{
    m_elapsed = millis() - m_offset;
    return m_elapsed;
}

void ArduinoTimer::reset()
{
    //_counterVal = 0;
    m_offset = millis();
    m_elapsed = 0;
}
