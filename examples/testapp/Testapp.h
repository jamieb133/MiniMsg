/**
 * @file Testapp.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-02-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef TESTAPP_H
#define TESTAPP_H

#include <Arduino.h>
#include <MiniMsg.h>
#include <ApplicationInterface.h>

using namespace MiniMsg;

class Testapp : public ApplicationInterface {
    public:
        Testapp();
        void tick();
        void on_message(bufferId_t bufferId);
        uint32_t tickPeriod();
        messageId_t id();

    private:
        int m_level;
        messageId_t m_msgId;
        uint32_t m_tickPeriod;
};

#endif // TESTAPP_H
