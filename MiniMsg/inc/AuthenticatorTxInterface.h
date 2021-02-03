/**
 * @file AuthenticatorTxInterface.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef AUTHENTICATORTXINTERFACE_H
#define AUTHENTICATORTXINTERFACE_H

#include "MiniMsg.h"

namespace MiniMsg {
    class AuthenticatorTxInterface {
        public:
            /**
             * @brief generate the authentication value and insert into the message buffer depending on specific authentication method (e.g. checksum, hash etc)
             * 
             * @param buffer_id 
             * @return int 
             */
            virtual void generate(bufferId_t id) = 0;
            
    
        protected:
            /**
             * @brief generate a hash from data in a specified message buffer and append it to that same message buffer
             * 
             * @param buffer_id index of buffer containing data to be hashed
             */
            virtual void add_hash(bufferId_t id) = 0;

        };
};
#endif // AUTHENTICATORTXINTERFACE_H
