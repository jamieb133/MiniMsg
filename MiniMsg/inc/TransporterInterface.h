/**
 * @file TransporterInterface.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef TRANSPORTERINTERFACE_H
#define TRANSPORTERINTERFACE_H

#include "MiniMsg.h"

namespace MiniMsg {
    class TransporterInterface {
        public:
            /**
             * @brief write data using the specific transport mechanism
             * 
             * @param buffer_id index of buffer containing encoded message to send 
             */
            virtual void send(bufferId_t bufferId) = 0;
            
    };
};

#endif // TRANSPORTERINTERFACE_H
