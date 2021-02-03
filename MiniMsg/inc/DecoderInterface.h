/**
 * @file DecoderInterface.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef DECODERINTERFACE_H
#define DECODERINTERFACE_H 

#include "MiniMsg.h"

namespace MiniMsg {
    class DecoderInterface {
        /**
         * @brief decode a specified buffer using this EncoderInterface's encoding format
         * 
         * @param encoded_buffer_id index of buffer containing data to be decoded
         * @return uint32_t index of buffer containing decoded data
         */
        virtual void decode(bufferId_t id) = 0;
    };
};

#endif // DECODERINTERFACE_H 