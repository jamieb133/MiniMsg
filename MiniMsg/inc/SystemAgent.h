/**
 * @file SystemAgent.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef SYSTEMAGENT_H
#define SYSTEMAGENT_H

#include "MiniMsg.h"
#include "SystemConfigInterface.h"
#include "SystemAgentInterface.h"
#include "ApplicationInterface.h"
#include "MessengerTxInterface.h"
#include "MessengerRxInterface.h"
#include "ValidatorTxInterface.h"
#include "ValidatorRxInterface.h"
#include "AuthenticatorTxInterface.h"
#include "AuthenticatorRxInterface.h"
#include "EncoderInterface.h"
#include "DecoderInterface.h"
#include "TransporterInterface.h"
#include "MonitorInterface.h"
#include "EventQueueInterface.h"
#include "TimerInterface.h"
#include "DebugInterface.h"

namespace MiniMsg {
    class SystemAgent : public SystemAgentInterface {
        private:
            static SystemAgent* s_instance;

            SystemAgent(SystemConfigInterface *config);


            ApplicationInterface* m_app;
            MessengerTxInterface* m_messengerTx;
            MessengerRxInterface* m_messengerRx;
            ValidatorTxInterface* m_validatorTx;
            ValidatorRxInterface* m_validatorRx;
            AuthenticatorTxInterface* m_authTx;
            AuthenticatorRxInterface* m_authRx;
            EncoderInterface* m_encoder;
            DecoderInterface* m_decoder;
            TransporterInterface* m_transporter;
            MonitorInterface* m_monitor;
            EventQueueInterface* m_eventQueue;
            TimerInterface* m_timer;

            bool m_running;

            //SystemAgent(uint32_t tickPeriod, ApplicationInterface *app);
            
        public:
            static void create_instance(SystemConfigInterface* config);
            //static void create_instance(uint32_t tickPeriod, ApplicationInterface *app);
            static SystemAgent* get_instance();
            void start();
            void stop();
            bool running();

            SystemAgent(const SystemAgent&) = delete;
            SystemAgent& operator=(const SystemAgent&) = delete;
    };
};

#endif // SYSTEMAGENT_H
