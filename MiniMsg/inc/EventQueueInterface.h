/**
 * @file EventQueueInterface.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef EVENTQUEUEINTERFACE_H
#define EVENTQUEUEINTERFACE_H

#include "MiniMsg.h"

namespace MiniMsg {
    class EventQueueInterface {
        public:
            virtual void push(uint8_t val) = 0;
            virtual uint8_t pop() = 0;
            virtual bool full() = 0;
    };
};

#endif // EVENTQUEUEINTERFACE_H
