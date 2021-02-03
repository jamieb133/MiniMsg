/**
 * @file TimerInterface.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-02-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef TIMERINTERFACE_H
#define TIMERINTERFACE_H

#include "MiniMsg.h"

namespace MiniMsg {

    class TimerInterface {

        public:
            virtual uint64_t time_elapsed() = 0;
            virtual void reset() = 0;
            
    };

};

#endif // TIMERINTERFACE_H

