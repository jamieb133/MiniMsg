/**
 * @file SystemAgent.cpp
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <Arduino.h>

#include "MiniMsg.h"
#include "SystemAgent.h"
#include "EventQueue.h"
#include "DebugInterface.h"

using namespace MiniMsg;

SystemAgent *SystemAgent::s_instance;

extern DebugInterface& get_debugger();

SystemAgent::SystemAgent(SystemConfigInterface* config)
{
    EventQueue::create_instance();
    m_app = config->app();
    m_messengerTx = config->messenger_tx();
    m_messengerRx = config->messenger_rx();
    m_validatorTx = config->validator_tx();
    m_validatorRx = config->validator_rx();
    m_authTx = config->authenticator_tx();
    m_authRx = config->authenticator_rx();
    m_encoder = config->encoder();
    m_decoder = config->decoder();
    m_transporter = config->transporter();
    m_monitor = config->monitor();
    m_eventQueue = config->eventQueue();
    m_timer = config->timer();
}

void SystemAgent::create_instance(SystemConfigInterface *config)
{
    static SystemAgent c_instance(config);
    s_instance = &c_instance;
}

SystemAgent* SystemAgent::get_instance()
{
    ASSERT(s_instance != nullptr, "tried to get NULL instance of SystemAgent");
    return s_instance;
}

void SystemAgent::start()
{
    SYSTEMDEBUG("SystemAgent started");

    m_running = true; 
    while( m_running ) { 
        // tick app if ready
        if (m_timer->time_elapsed() >= m_app->tickPeriod())
        {
            m_app->tick();
            m_timer->reset();
        }    

        // poll input
        //m_monitor->poll();

        // handle next event
    }
    

    /*
    messageId_t msgId;

    m_running = true;

    //event loop
    EventQueue& eventQueue = EventQueue::get_instance();

    while(this->running())
    {
        // poll input
        m_monitor.poll();

        // handle next event
        event = eventQueue.pop();
        switch(event.type)
        {
            case APP:
                m_app.on_message(event.bufferId);
                break;
            case MSG_TX:
                msgId = m_app.id();
                m_messengerTx.add_message_id(event.bufferId, msgId);
                break;
            case MSG_RX:
                m_messengerRx.parse_message(event.bufferId);
                break;
            case VAL_TX:
                m_validatorTx.add_validator(event.bufferId);
                break;
            case VAl_RX:
                m_validatorRx.validate(event.bufferId);
                break;
            case AUTH_TX:
                m_authenticatorTx.generate(event.bufferId);
                break;
            case AUTH_RX:
                m_authenticatorRx.add_hash(event.bufferId);
                break;
            case SEND:
                m_transporter.send(event.bufferId);
                break;
            default:
                assert(0);
        }
    }
    */
}

void SystemAgent::stop()
{
    // TODO: add guard
    m_running = false;
}

bool SystemAgent::running()
{
    return m_running;
}
