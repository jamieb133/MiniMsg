/**
 * @file DebugInterface.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-02-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef DEBUGINTERFACE_H
#define DEBUGINTERFACE_H

#include "MiniMsg.h"

#define SYSTEMDEBUG(s) get_debugger().print(s)
#define ASSERT(e,s) get_debugger().err_check(e,s)

namespace MiniMsg {
    class DebugInterface {

        public:
            virtual void print(const char* string) = 0;
            virtual void print(long longInt) = 0;
            virtual void err_check(uint32_t expression, const char* errorMsg) = 0;

    };

    /**
     * @brief global function should be defined by user for specific debug interface
     * 
     * @return DebugInterface& 
     */
    DebugInterface& get_debugger();

};

#endif // DEBUGINTERFACE_H
