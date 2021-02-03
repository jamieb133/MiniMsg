/**
 * @file EventQueue.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

#include "MiniMsg.h"
#include "EventQueueInterface.h"

namespace MiniMsg {
    enum eventType_t {
        APP,
        MSG_TX,
        MSG_RX,
        MONITOR,
        VAL_TX, 
        VAL_RX,
        AUTH_TX,
        AUTH_RX,
        ENCODE,
        DECODE,
        SEND
    };

    typedef struct event {
        eventType_t type;
        bufferId_t bufferId;
    }event_t;

    class EventQueue : public EventQueueInterface {
        friend class SystemAgent;
        private:
            static EventQueue* s_instance;
            event_t m_events[EVENT_QUEUE_LENGTH];
            bool m_full;
            EventQueue();
        protected:
            uint8_t pop();
            void push(uint8_t val);
        public:
            static void create_instance();
            static EventQueue& get_instance();
            bool full();
    };

};


#endif // EVENTQUEUE_H

