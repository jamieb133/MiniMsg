/**
 * @file ApplicationInterface.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef APPLICATIONINTERFACE_H
#define APPLICATIONINTERFACE_H

static const uint32_t DEFAULT_TICK = 1000; // ms

namespace MiniMsg {
    class ApplicationInterface {
    public:
        /**
         * @brief main application callback routine
         * 
         */
        virtual void tick() = 0;
        
        /**
         * @brief message received callback
         * 
         * @param bufferId index of buffer containing the message
         */
        virtual void on_message(bufferId_t bufferId) = 0;

        virtual messageId_t id() = 0;
        //virtual uint32_t tickPeriod() { return DEFAULT_TICK; }
        virtual uint32_t tickPeriod() = 0;
    };
};

#endif //APPLICATIONINTERFACE_H
