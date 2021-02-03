#include "App.h"
#include <SystemConfig.h>

using namespace MiniMsg;

SystemConfig* SystemConfig::s_instance;

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
    // create instance of timer

    // set timer interface

}

void SystemConfig::setup_debug()
{
    // create instance of system debug
}

void SystemConfig::setup_layers()
{
    // set user app
    static App c_app;
    m_app = &c_app;
    
    // create instance of event queue (e.g. EventQueue)
    // set event queue interface
    ...

    // create instance of messenger (e.g. Messenger)
    // set messenger rx/tx interfaces
    ...

    // create instance of validator (e.g. LengthValidator)
    // set validator rx/tx interfaces
    ...

    // create instance of authenticator (e.g. CMACAuthenticator)
    // set authenticator rx/tx interfaces
    ...

    // create instance of encoder/decoder (e.g. COBSEncoder)
    // set encoder and decoder interfaces
    ...

    // create instance of monitor/transporter (e.g. ArduinoStuffer)
    // set monitor and transporter interfaces (with relevant decoder as above)
    ...
}

// system-wide getter function for the concrete debug interface
DebugInterface& MiniMsg::get_debugger()
{
    // return <concrete debug class>>::get_instance();
}
