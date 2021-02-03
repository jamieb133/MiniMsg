#include "Testapp.h"
#include <Arduino.h>
#include <DebugInterface.h>
#include <ArduinoTimer.h>

using namespace MiniMsg;

static const uint32_t TICK_PERIOD = 1000; // ms
static const messageId_t MESSAGE_ID = 1; 

Testapp::Testapp()
{
    m_level = HIGH;
    m_tickPeriod = TICK_PERIOD;
    m_msgId = MESSAGE_ID;
}

void Testapp::tick()
{   
    uint64_t time;
    
    digitalWrite(LED_BUILTIN, m_level);
    m_level = !m_level;
    SYSTEMDEBUG("hello!");
}

void Testapp::on_message(bufferId_t bufferId) 
{

}
