#include "BufferManager.h"
#include "DebugInterface.h"

using namespace MiniMsg;

BufferManager *BufferManager::s_instance;

Buffer _deviceBuffers[NUM_OF_BUFS];

BufferManager::BufferManager()
{
}

void BufferManager::create_instance()
{
    static BufferManager instance;
    s_instance = &instance;
}

BufferManager* BufferManager::get_instance()
{
    ASSERT(s_instance != nullptr, "tried to get NULL instance of BufferManager");
    return s_instance;
}

bufferId_t BufferManager::request_buffer()
{
    // TODO: better search algorithm
    for(int i = 0; i < NUM_OF_BUFS; i++)
    {
        if (_deviceBuffers[i].state() == UNLOCKED)
        {
            _deviceBuffers[i].set_state(UNLOCKED);
            return i;
        }
    }
    // no buffers available, something went wrong
    assert(0);
}

void BufferManager::release_buffer(bufferId_t id)
{
    // check buffer is not already UNLOCKED
    assert(_deviceBuffers[id].state() != UNLOCKED);
    _deviceBuffers[id].set_state(LOCKED);
}
