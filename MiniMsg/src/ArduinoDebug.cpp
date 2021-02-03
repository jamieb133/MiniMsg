#include "MiniMsg.h"
#include "ArduinoDebug.h"
#include <Arduino.h>

using namespace MiniMsg;

ArduinoDebug* ArduinoDebug::s_instance;

void ArduinoDebug::create_instance()
{
    static ArduinoDebug c_instance;
    s_instance = &c_instance;
}

ArduinoDebug& ArduinoDebug::get_instance()
{
    err_check_internal(s_instance != nullptr, "tried to get NULL instance of ArduinoDebug");
    return *s_instance;
}

ArduinoDebug::ArduinoDebug()
{
    Serial.begin(9600);
    print("[WARNING] hardware serial used");
}

void ArduinoDebug::print(const char* msg)
{
    Serial.print(msg);
    Serial.print("\n\r");
}

void ArduinoDebug::print(long msg)
{
    Serial.print(msg);
    Serial.print("\n\r");
}

void ArduinoDebug::err_check_internal(uint32_t expression, const char* msg)
{
    if(s_instance == nullptr)
        Serial.begin(9600);

#ifndef HARD_ASSERT
    while(!expression)
    {
        // error found, enter endless loop and print message periodically
        Serial.print("[ERROR] ");
        Serial.print(msg);
        Serial.print("\n\r");
        delay(2000);
    }
#else
    if (!expression)
    {
        // print just once and hard assert
        print(msg);
        assert(expression);
    }
#endif // HARD_ASSERT 
}

void ArduinoDebug::err_check(uint32_t expression, const char* msg)
{  
    err_check_internal(expression, msg);
}
