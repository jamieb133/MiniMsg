#include "Buffer.h"

//namespace MiniMsg {
    
using namespace MiniMsg;

Buffer::Buffer()
{

}

uint8_t Buffer::val(bufferId_t id)
{
    assert(m_state != UNLOCKED);
    return m_data[id];
}

void Buffer::set_val(uint8_t val, bufferId_t id)
{
    assert(m_state != UNLOCKED);
    m_data[id] = val;
}

bufferState_t Buffer::state()
{
    return m_state;
}

void Buffer::set_state(bufferState_t state)
{
    m_state = state;
}

//};
