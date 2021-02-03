/**
 * @file MessengerRxInterface.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef MESSENGERRXINTERFACE_H
#define MESSENGERRXINTERFACE_H

#include "MiniMsg.h"

namespace MiniMsg {
    class MessengerRxInterface {
        /**
         * @brief parse message id
         * 
         * @return bufferId_t buffer index of the message
         */
        virtual void parse_message(bufferId_t id) = 0;
    };
};


#endif // MESSENGERRXINTERFACE_H 