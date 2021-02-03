/**
 * @file ValidatorTxInterface.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef VALIDATORTXINTERFACE_H
#define VALIDATORTXINTERFACE_H

#include "MiniMsg.h"

namespace MiniMsg {
    class ValidatorTxInterface {
        public:
            /**
             * @brief 
             * 
             * @param buffer_id 
             */
            virtual void validate(bufferId_t buffer_id) = 0;
    };
};

#endif // VALIDATORTXINTERFACE_H
