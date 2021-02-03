#include "MiniMsg.h"
#include "DebugInterface.h"

namespace MiniMsg {
    namespace Debug {
        /**
         * @brief returns the concrete system-wide print interface, should be defined by user (SystemConfig.cpp)
         * 
         * @return DebugInterface& 
         */
        DebugInterface& debugger();
    };
};
