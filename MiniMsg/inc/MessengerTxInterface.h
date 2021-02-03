/**
 * @file MessageHandlerInterface.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef MESSENBGERTXINTERFACE_H
#define MESSENBGERTXINTERFACE_H

#include "MiniMsg.h"

namespace MiniMsg {
    class MessengerTxInterface {
        public:
        /**
         * @brief construct a message
         * 
         * @param bufId index of buffer containing data to set
         * @param msgId message id of this message 
         */
        virtual void set_message_id(bufferId_t bufId, messageId_t msgId) = 0;
    };
};


#endif // MESSAGEHANDLERINTERFACE_H 
