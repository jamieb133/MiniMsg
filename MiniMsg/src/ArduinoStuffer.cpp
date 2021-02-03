#include "ArduinoStuffer.h"
#include "DebugInterface.h"
#include "BufferManager.h" 
#include "Arduino.h"

using namespace MiniMsg;

static const int DEFAULT_BAUD = 9600;

ArduinoStuffer *ArduinoStuffer::s_instance;

ArduinoStuffer::ArduinoStuffer(EncoderInterface& encoder, DecoderInterface& decoder)
{
    m_encoder = &encoder;
    m_decoder = &decoder;
    m_baud = DEFAULT_BAUD;
}

void ArduinoStuffer::create_instance(EncoderInterface& encoder, DecoderInterface& decoder)
{
    static ArduinoStuffer c_instance(encoder, decoder);
    s_instance = &c_instance;
}

ArduinoStuffer& ArduinoStuffer::get_instance()
{
    ASSERT(s_instance != nullptr, "tried to get NULL instance of ArduinoStuffer");
    return *s_instance;
}

void ArduinoStuffer::send(bufferId_t bufferId)
{
 //   Serial.write(_deviceBuffers[bufferId]);
}

void ArduinoStuffer::poll()
{
    // DebugInterface& debug = get_debugger();
    // while (Serial.available() > 0)
    // {
    //     debug.print("RECEIVED:");
    //     debug.print(Serial.read());
    // }

    // uint8_t offset, currentIndex, currentByte, nextStuffedIndex;
    //
    // while (Serial.available() > 0) 
    // {
    //      // AWAITING START BYTE
    //      if (Serial.read() == 0x00)
    //      {
    //          // PACKET LOCKED
    //          offset = 0;
    //          currentIndex = 0;
    //          nextStuffedIndex = Serial.read();
    //          while( != nextStuffedIndex)      
    //      ...
    //      ... etc
    //             
    // }
}
