/**
 * @file Messenger.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef MESSENGER_H
#define MESSENGER_H

#include "MessengerRxInterface.h"
#include "MessengerTxInterface.h"
#include "EventQueueInterface.h"

namespace MiniMsg {
class Messenger : public MessengerTxInterface, public MessengerRxInterface {
    public:
        /**
         * @brief Construct a new Message Handler object
         * 
         * @param eventQueue 
         */
        Messenger(EventQueueInterface* eventQueue);

        void parse_message(bufferId_t id);
        void set_message_id(bufferId_t bufId, messageId_t msgId);
        static void create_instance(EventQueueInterface* eventQueue);
        static Messenger& get_instance();

    private:
        static Messenger *s_instance;
        EventQueueInterface* m_eventQueue;
    };
};


#endif // MESSENGER_H
