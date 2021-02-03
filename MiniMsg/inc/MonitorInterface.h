/**
 * @file MonitorInterface.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef MONITOR_H
#define MONITOR_H

#include "MiniMsg.h"

namespace MiniMsg {
    class MonitorInterface {
        public:
            virtual void poll() = 0;
    };
};

#endif // MONITOR_H
