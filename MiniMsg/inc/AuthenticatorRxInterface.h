/**
 * @file AuthenticatorInterface.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef AUTHENTICATORRXINTERFACE_H
#define AUTHENTICATORRXINTERFACE_H

#include "MiniMsg.h"

namespace MiniMsg
{
    class AuthenticatorRxInterface {
        public:
            /**
             * @brief verify a hash from input data
             * 
             * @param bufferId index of buffer containing data to verify and the mac
             * @param keyId index of key buffer that will be used to generate the hash
             */
            virtual void verify(bufferId_t bufferId, keyId_t keyId) = 0;
    };
}; // namespace MiniMsg

#endif // AUTHENTICATORRXINTERFACE_H
