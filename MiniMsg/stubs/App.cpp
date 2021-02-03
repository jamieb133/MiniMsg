#include "App.h"

using namespace MiniMsg;

static const uint32_t TICK_PERIOD = 1000; // ms
static const messageId_t MESSAGE_ID = 1; 

App::App()
{
    m_tickPeriod = TICK_PERIOD;
    m_msgId = MESSAGE_ID;
}

void App::tick()
{   
}

void App::on_message(bufferId_t bufferId) 
{
}

void App::tickPeriod()
{
    return m_tickPeriod;
}

void App::id()
{
    return m_msgId;
}
