/**
 * @file ArduinoDebug.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-02-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef ARDUINODEBUG_H
#define ARDUINODEBUG_H

#include "MiniMsg.h"
#include "DebugInterface.h"

namespace MiniMsg {

    class ArduinoDebug : public DebugInterface {
        private:
            static ArduinoDebug* s_instance;
            ArduinoDebug();
            static void err_check_internal(uint32_t expression, const char* errorMsg);
        public:
            static void create_instance();
            static ArduinoDebug& get_instance();
            void print(const char* msg);
            void print(long msg);
            void err_check(uint32_t expression, const char* errorMsg);

    };


};

#endif // ARDUINODEBUG_H