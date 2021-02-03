#include "Testapp.h"

#include <MiniMsg.h>
#include <ArduinoStuffer.h>
#include <CMACAuthenticator.h>
#include <COBS.h>
#include <LengthValidator.h>
#include <Messenger.h>
#include <EventQueue.h>
#include <ArduinoDebug.h>
#include <ArduinoTimer.h>
#include <Arduino.h>
#include <DebugInterface.h>

#include <SystemConfig.h>

using namespace MiniMsg;
//using namespace MiniMsg::Debug;

SystemConfig* SystemConfig::s_instance;

//extern DebugInterface& get_debugger();

void SystemConfig::create_instance()
{
    static SystemConfig c_instance;
    s_instance = &c_instance;
}
SystemConfig& SystemConfig::get_instance()
{
    ASSERT(s_instance != nullptr, "tried to get NULL instance of SystemConfig");
    return *s_instance;
}

void SystemConfig::setup_ticker()
{
    ArduinoTimer::create_instance();
    m_timer = &ArduinoTimer::get_instance();
}

void SystemConfig::setup_debug()
{
    ArduinoDebug::create_instance();
}

void SystemConfig::setup_layers()
{
    // user application layer
    static Testapp c_app;
    m_app = &c_app;
    
    // event queue
    EventQueue::create_instance();
    m_eventQueue = &EventQueue::get_instance();

    // layer 4
    Messenger::create_instance(m_eventQueue);
    m_msgTx = &Messenger::get_instance();
    m_msgRx = &Messenger::get_instance();

    // layer 3
    LengthValidator::create_instance();
    m_valTx = &LengthValidator::get_instance();
    m_valRx = &LengthValidator::get_instance();

    // layer 2
    CMACAuthenticator::create_instance();
    m_authTx = &CMACAuthenticator::get_instance();
    m_authRx = &CMACAuthenticator::get_instance();

    COBS::create_instance();
    m_encoder = &COBS::get_instance();
    m_decoder = &COBS::get_instance();

    // layer 1
    ArduinoStuffer::create_instance(*m_encoder, *m_decoder);
    m_monitor = &ArduinoStuffer::get_instance();
    m_transporter = &ArduinoStuffer::get_instance();
}

DebugInterface& MiniMsg::get_debugger()
{
    return ArduinoDebug::get_instance();
}
