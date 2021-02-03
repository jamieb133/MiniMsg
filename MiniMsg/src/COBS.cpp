#include "COBS.h"
#include "DebugInterface.h"

using namespace MiniMsg;

COBS *COBS::s_instance;

COBS::COBS()
{

}

void COBS::create_instance()
{
    static COBS c_instance;
    s_instance = &c_instance;
}

COBS& COBS::get_instance()
{
    ASSERT(s_instance != nullptr, "tried to get NULL instance of COBS");
    return *s_instance;
}

void COBS::decode(bufferId_t id)
{
    
}

void COBS::encode(bufferId_t id)
{

}
