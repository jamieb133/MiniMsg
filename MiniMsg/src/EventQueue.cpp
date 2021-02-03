#include "EventQueue.h"
#include "DebugInterface.h"

using namespace MiniMsg;

EventQueue *EventQueue::s_instance;

EventQueue::EventQueue()
{
    m_full = false;
}

void EventQueue::create_instance()
{
    static EventQueue c_instance;
    s_instance = &c_instance;
}

EventQueue& EventQueue::get_instance()
{
    ASSERT(s_instance != nullptr, "tried to get NULL instance of EventQueue");
    return *s_instance;
}

void EventQueue::push(uint8_t val)
{

}

uint8_t EventQueue::pop()
{

}

bool EventQueue::full()
{
    return m_full;
}

