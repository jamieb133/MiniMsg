/**
 * @file ArduinoTimer.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-02-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef ARDUINOTIMER_H
#define ARDUINOTIMER_H

#include "MiniMsg.h"
#include "TimerInterface.h"
#include "DebugInterface.h"

namespace MiniMsg {

    class ArduinoTimer : public TimerInterface {

        private:
            ArduinoTimer();
            static ArduinoTimer* s_instance;
            uint64_t m_elapsed, m_offset;
        public:
            static void create_instance();
            static ArduinoTimer& get_instance();
            uint64_t time_elapsed();
            void reset();
    };

};

#endif // ARDUINOTIMER_H


















