/**
 * @file EncoderInterface.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef ENCODERINTERFACE_H
#define ENCODERINTERFACE_H 

#include "MiniMsg.h"

namespace MiniMsg {
    class EncoderInterface {
        /**
         * @brief encode a specified buffer using this EncoderInterface's encoding format
         * 
         * @param unencoded_buffer_id index of buffer containing data to be encoded
         * @return uint32_t index of buffer containing encoded data
         */
        virtual void encode(bufferId_t id) = 0;
    };
};

#endif // ENCODERINTERFACE_H 
