/**
 * @file CMACAuthenticator.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CMACAUTHENTICATOR_H
#define CMACAUTHENTICATOR_H

#include "MiniMsg.h"

#include "AuthenticatorTxInterface.h"
#include "AuthenticatorRxInterface.h"

namespace MiniMsg
{
    class CMACAuthenticator : public AuthenticatorRxInterface, public AuthenticatorTxInterface {
        public:
            /**
             * @brief Construct a new CMACAuthenticator object
             * 
             */
            CMACAuthenticator();

            /**
             * @brief 
             * 
             * @param bufferId 
             * @param keyId 
             */
            void verify(bufferId_t bufferId, keyId_t keyId);

            /**
             * @brief generate the authentication value and insert into the message buffer depending on specific authentication method (e.g. checksum, hash etc)
             * 
             * @param buffer_id 
             * @return int 
             */
            void generate(bufferId_t id);
            
            static void create_instance();
            static CMACAuthenticator& get_instance();
        private:
            
            static CMACAuthenticator *s_instance;

            /**
             * @brief generate a hash from data in a specified message buffer and append it to that same message buffer
             * 
             * @param buffer_id index of buffer containing data to be hashed
             */
            void add_hash(bufferId_t id);

    };
}; 

#endif //CMACAUTHENTICATOR_H
