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

namespace MiniMsg {
    class ApplicationInterface {
    protected:
        uint32_t m_tickPeriod;
        messageId_t m_msgId;
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

        messageId_t id() { return m_msgId; }
        uint32_t tickPeriod() { return m_tickPeriod; }
    };
};

#endif //APPLICATIONINTERFACE_H
