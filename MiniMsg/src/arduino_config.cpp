#include <Arduino.h>
#include <MiniMsg.h>
#include <SystemConfig.h>
#include <SystemAgent.h>
#include "DebugInterface.h"

using namespace MiniMsg;

void setup()
{
    // debugging pin
    pinMode(LED_BUILTIN, OUTPUT);

    SystemConfig::create_instance();
    SystemConfig systemConfig = SystemConfig::get_instance();
    SystemAgent::create_instance(&systemConfig);    
}

void loop() 
{
    // digitalWrite(LED_BUILTIN, HIGH);
    // delay(500);
    // digitalWrite(LED_BUILTIN, LOW);
    // delay(500);

    // start system agent event loop
    SystemAgent* systemAgent = SystemAgent::get_instance();
    systemAgent->start(); 
    SYSTEMDEBUG("[WARNING] restarting SystemAgent");
}
