/**
 * @file SystemConfig.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-02-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef SYSTEMCONFIG_H
#define SYSTEMCONFIG_H

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
#include "SystemConfigInterface.h"
#include "DebugInterface.h"

namespace MiniMsg {
    class SystemConfig : public SystemConfigInterface {
        private:
            
            void setup_layers();
            void setup_debug();
            void setup_ticker();

            static SystemConfig *s_instance;

            ApplicationInterface* m_app = nullptr;
            AuthenticatorTxInterface* m_authTx = nullptr;
            AuthenticatorRxInterface* m_authRx = nullptr;
            EncoderInterface* m_encoder = nullptr;
            DecoderInterface* m_decoder = nullptr;
            MessengerTxInterface* m_msgTx = nullptr;
            MessengerRxInterface* m_msgRx = nullptr;
            MonitorInterface* m_monitor = nullptr;
            TransporterInterface* m_transporter = nullptr;
            ValidatorTxInterface* m_valTx = nullptr;
            ValidatorRxInterface* m_valRx = nullptr;
            EventQueueInterface* m_eventQueue = nullptr;
            TimerInterface* m_timer = nullptr;

            SystemConfig()
            {
                this->setup_debug();
                this->setup_ticker();
                this->setup_layers();

                // check the user set all handles
                ASSERT(m_app != nullptr, "m_app is NULL for SystemConfig");
                ASSERT(m_authTx != nullptr, "m_authTx is NULL for SystemConfig");
                ASSERT(m_authRx != nullptr, "m_authRx is NULL for SystemConfig");
                ASSERT(m_encoder != nullptr, "m_encoder is NULL for SystemConfig");
                ASSERT(m_decoder != nullptr, "m_decoder is NULL for SystemConfig");
                ASSERT(m_msgTx != nullptr, "m_msgTx is NULL for SystemConfig");
                ASSERT(m_msgRx != nullptr, "m_msgRx is NULL for SystemConfig");
                ASSERT(m_monitor != nullptr, "m_monitor is NULL for SystemConfig");
                ASSERT(m_transporter != nullptr, "m_transporter is NULL for SystemConfig");
                ASSERT(m_valTx != nullptr, "m_valTx is NULL for SystemConfig");
                ASSERT(m_valRx != nullptr, "m_valRx is NULL for SystemConfig");
                ASSERT(m_timer != nullptr, "m_timer is NULL for SystemConfig");

                SYSTEMDEBUG("Finished SystemConfig");
            }

        public:
            static void create_instance();
            static SystemConfig& get_instance();

            ApplicationInterface *app() 
            {
                assert(m_app != nullptr);
                return m_app;
            }
            AuthenticatorTxInterface *authenticator_tx()
            {            
                assert(m_authTx != nullptr);
                return m_authTx;
            }
            AuthenticatorRxInterface *authenticator_rx()
            {            
                assert(m_authRx != nullptr);
                return m_authRx;
            }
            EncoderInterface *encoder()
            {            
                assert(m_encoder != nullptr);
                return m_encoder;
            }
            DecoderInterface *decoder()
            {            
                assert(m_decoder != nullptr);
                return m_decoder;
            }
            MessengerTxInterface *messenger_tx()
            {            
                assert(m_msgTx != nullptr);
                return m_msgTx;
            }
            MessengerRxInterface *messenger_rx()
            {            
                assert(m_msgRx != nullptr);
                return m_msgRx;
            }
            MonitorInterface *monitor()
            {            
                assert(m_monitor != nullptr);
                return m_monitor;
            }
            TransporterInterface *transporter()
            {            
                assert(m_transporter != nullptr);
                return m_transporter;
            }
            ValidatorTxInterface *validator_tx()
            {            
                assert(m_valTx != nullptr);
                return m_valTx;
            }
            ValidatorRxInterface *validator_rx()
            {            
                assert(m_valRx != nullptr);
                return m_valRx;
            }
            EventQueueInterface *eventQueue()
            {
                assert(m_eventQueue != nullptr);
                return m_eventQueue;
            }
            TimerInterface *timer()
            {
                assert(m_timer != nullptr);
                return m_timer;
            }

            
    };
};

#endif // SYSTEMCONFIG_H
