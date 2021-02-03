/**
 * @file ValidatorRxInterface.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef VALIDATORRXINTERFACE_H
#define VALIDATORRXINTERFACE_H

#include "MiniMsg.h"

namespace MiniMsg {
    class ValidatorRxInterface {
        public:
            /**
             * @brief 
             * 
             * @param buffer_id 
             */
            virtual void add_validator(bufferId_t buffer_id) = 0;
    };
};

#endif // VALIDATORRXINTERFACE_H