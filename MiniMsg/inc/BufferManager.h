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

#ifndef BUFFERMANAGER_H
#define BUFFERMANAGER_H

#include "MiniMsg.h"
#include "BufferManagerInterface.h"
#include "Buffer.h"

namespace MiniMsg 
{
    

    class BufferManager 
    {
        private:
            /**
             * @brief BufferManager singleton
             * 
             */
            static BufferManager* s_instance;
            
            /**
             * @brief private constructor, prevent instancing
             * 
             */
            BufferManager();
            
            BufferManager(const BufferManager&) = delete;
            BufferManager& operator= (const BufferManager&) = delete;

        public:
            /**
             * @brief static constructor
             * 
             */
            static void create_instance();

            static BufferManager* get_instance();

            /**
             * @brief find the next available buffer, asserts if none available
             * 
             * @return uint64_t bufferId of new buffer 
             */
            bufferId_t request_buffer();

            /**
             * @brief reliquish buffer. State returns to AVAILABLE.
             * 
             * @param id  
             */
            void release_buffer(bufferId_t id);
        
    };
};

#endif // BUFFERMANAGER_H
