/**
 * @file LengthValidator.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef LENGTHVALIDATOR_H
#define LENGTHVALIDATOR_H

#include "MiniMsg.h"
#include "ValidatorTxInterface.h"
#include "ValidatorRxInterface.h"

namespace MiniMsg {
    class LengthValidator : public ValidatorTxInterface, public ValidatorRxInterface {
        public:
            static void create_instance();
            static LengthValidator& get_instance();
          
            void validate(bufferId_t bufferId);

            void add_validator(bufferId_t bufferId);
        private:
            static LengthValidator *s_instance;
            LengthValidator();

            /**
             * @brief parse the message length field from a message
             * 
             * @param buffer_id index of buffer containing the message to get length byte from
             * @return uint8_t value of the message length byte
             */
            uint8_t get_length_byte(bufferId_t buffer_id);
            
            /**
             * @brief calculate the true length of a message
             * 
             * @param buffer_id index of buffer containing the message to calculate length of
             * @return uint8_t calculated value of the message length
             */
            uint8_t get_true_length(bufferId_t buffer_id);

            /**
             * @brief set the length field of an outbound message
             * 
             * @param length 
             * @param buffer_id 
             */
            void set_length_byte(uint8_t length, bufferId_t buffer_id);
    };
};

#endif // LENGTHVALIDATOR_H