/**
 * @file Buffer.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef BASICBUFFER_H
#define BASICBUFFER_H

#include "MiniMsg.h"
#include "BufferInterface.h"

namespace MiniMsg {
    class Buffer : protected BufferInterface {
    friend class BufferManager;
    public:
        /**
         * @brief Construct a new Buffer object
         * 
         */
        Buffer();

        uint8_t val(bufferId_t id);
        void set_val(uint8_t val, bufferId_t id);
        bufferState_t state();
    
    protected:
        void set_state(bufferState_t state);
    
    private:
        uint8_t m_data[MAX_BUFFER_SIZE];
        bufferState_t m_state;
    };
};

#endif // BASICBUFFER_H
