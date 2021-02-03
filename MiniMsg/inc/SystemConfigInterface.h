/**
 * @file SystemConfigInterface.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-02-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef SYSTEMCONFIGINTERFACE_H
#define SYSTEMCONFIGINTERFACE_H

#include "MiniMsg.h"
#include "ApplicationInterface.h"
#include "AuthenticatorTxInterface.h"
#include "AuthenticatorRxInterface.h"
#include "EncoderInterface.h"
#include "DecoderInterface.h"
#include "MessengerTxInterface.h"
#include "MessengerRxInterface.h"
#include "TransporterInterface.h"
#include "MonitorInterface.h"
#include "ValidatorTxInterface.h"
#include "ValidatorRxInterface.h"
#include "EventQueueInterface.h"
#include "TimerInterface.h"

namespace MiniMsg {
    class SystemConfigInterface {
        public:
            virtual ApplicationInterface *app() = 0;
            virtual AuthenticatorTxInterface *authenticator_tx() = 0;
            virtual AuthenticatorRxInterface *authenticator_rx() = 0;
            virtual EncoderInterface *encoder() = 0;
            virtual DecoderInterface *decoder() = 0;
            virtual MessengerTxInterface *messenger_tx() = 0;
            virtual MessengerRxInterface *messenger_rx() = 0;
            virtual MonitorInterface *monitor() = 0;
            virtual TransporterInterface *transporter() = 0;
            virtual ValidatorTxInterface *validator_tx() = 0;
            virtual ValidatorRxInterface *validator_rx() = 0; 
            virtual EventQueueInterface *eventQueue() = 0; 
            virtual TimerInterface *timer() = 0; 
    };
};

#endif // SYSTEMCONFIGINTERFACE_H
