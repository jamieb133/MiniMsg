/**
 * @file COBS.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef COBS_H
#define COBS_H

#include "MiniMsg.h"
#include "EncoderInterface.h"
#include "DecoderInterface.h"

namespace MiniMsg {
    /**
     * @brief for encoding/decoding in Consistent Overhead Byte Stuffing (COBS) format 
     * 
     */
    class COBS : public EncoderInterface, public DecoderInterface {
        private:
            /**
             * @brief Construct a new COBS object
             * 
             */
            COBS();

            static COBS* s_instance;

            COBS(const COBS&) = delete;
            COBS& operator= (const COBS&) = delete;

        public:
            static void create_instance();
            static COBS& get_instance();
            void decode(bufferId_t id);
            void encode(bufferId_t id);
    };
};

#endif // COBS_H
