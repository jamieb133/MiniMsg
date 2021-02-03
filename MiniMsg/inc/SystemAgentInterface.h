/**
 * @file SystemAgentInterface.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef SYSTEMAGENTINTERFACE_H
#define SYSTEMAGENTINTERFACE_H

#include "MiniMsg.h"

namespace MiniMsg {
    class SystemAgentInterface {
        public:
            virtual void start() = 0;
            virtual void stop() = 0;
            virtual bool running() = 0;
    };
};

#endif // SYSTEMAGENTINTERFACE_H


