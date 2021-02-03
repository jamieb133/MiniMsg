/**
 * @file BufferInterface.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef BUFFERINTERFACE_H
#define BUFFERINTERFACE_H

#include "MiniMsg.h"

namespace MiniMsg {
    class BufferInterface {
        public:
            virtual uint8_t val(bufferId_t id) = 0;
            virtual void set_val(uint8_t val, bufferId_t id) = 0;
            virtual bufferState_t state() = 0;
        protected:
            virtual void set_state(bufferState_t state) = 0;
    };
};

#endif // BUFFERINTERFACE_H
