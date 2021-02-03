#include "Messenger.h"
#include "DebugInterface.h"

namespace MiniMsg {
    Messenger* Messenger::s_instance;

    void Messenger::create_instance(EventQueueInterface* eventQueue)
    {
        static Messenger c_instance(eventQueue);
        s_instance = &c_instance;
    }

    Messenger& Messenger::get_instance()
    {
        ASSERT(s_instance != nullptr, "tried to get NULL instance of Messenger");
        return *s_instance;
    }

    Messenger::Messenger(EventQueueInterface* eventQueue)
    {
        m_eventQueue = eventQueue;
    }

    void Messenger::parse_message(bufferId_t)
    {

    }

    void Messenger::set_message_id(bufferId_t bufId, messageId_t msgId)
    {

    }

};
