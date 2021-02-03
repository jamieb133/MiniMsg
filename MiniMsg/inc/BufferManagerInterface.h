/**
 * @file BufferManager.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef BUFFERMANAGERINTERFACE_H
#define BUFFERMANAGERINTERFACE_H

#include "MiniMsg.h"
#include "BufferInterface.h"

namespace MiniMsg 
{
    class BufferManagerInterface 
    {
        public:
   

            /**
             * @brief find the next available buffer, asserts if none available
             * 
             * @return uint64_t bufferId of new buffer 
             */
            virtual bufferId_t request_buffer() = 0;

            /**
             * @brief reliquish buffer. State returns to AVAILABLE.
             * 
             * @param id  
             */
            virtual void release_buffer(bufferId_t id) = 0;
    };
};

#endif // BUFFERMANAGERINTERFACE_H
