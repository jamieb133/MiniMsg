/**
 * @file MiniMsg.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef MINIMSG_H
#define MINIMSG_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>

const int MAX_BUFFER_SIZE = 256; // number of individual bytes to statically allocate for each buffer
const int NUM_OF_BUFS = 20; // number of buffers to statically allocate
const int EVENT_QUEUE_LENGTH = 10; // number of events to buffer

namespace MiniMsg {

    enum bufferState_t {
        UNLOCKED,
        LOCKED,     // immediately changed from LOCKED after requested, contents unchanged
        READING,
        WRITING,
        ENCODED,
        DECODED,
        AUTHENTICATED,
        VALIDATED,
        READY
    };

    typedef uint64_t bufferId_t ;
    typedef uint64_t keyId_t ;
    typedef uint64_t messageId_t ;

};

#endif // MINIMSG_H
