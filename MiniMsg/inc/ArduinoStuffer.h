/**
 * @file ArduinoStuffer.h
 * @author Jamie Brown 
 * @brief 
 * @version 0.1
 * @date 2021-01-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef ARDUINOSTUFFER_H
#define ARDUINOSTUFFER_H

#include "MiniMsg.h"
#include "TransporterInterface.h"
#include "MonitorInterface.h"
#include "EncoderInterface.h"
#include "DecoderInterface.h"

namespace MiniMsg 
{
    class ArduinoStuffer : public TransporterInterface , public MonitorInterface
    {
        private:
            /**
             * @brief Construct a new Software Serial Transporter object
             * 
             */
            ArduinoStuffer(EncoderInterface& encoder, DecoderInterface& decoder);

            /**
             * @brief singleton SoftwareSerialTransporter instance 
             * 
             */
            static ArduinoStuffer *s_instance;
            uint32_t m_baud;
            EncoderInterface* m_encoder = nullptr;
            DecoderInterface* m_decoder = nullptr;


        public:
            static void create_instance(EncoderInterface& encoder, DecoderInterface& decoder);
            static ArduinoStuffer& get_instance();

            ArduinoStuffer(const ArduinoStuffer&) = delete;
            ArduinoStuffer& operator=(const ArduinoStuffer&) = delete;

            void set_baud();

            /**
             * @brief send data using a serial driver
             * 
             * @param buffer_id index of buffer containing encoded message to send 
             */
            void send(bufferId_t buffer_id);
            
            /**
             * @brief check the serial input for any data and raise an event if locked onto a packet
             * 
             */
            void poll();


    };
};

#endif //ARDUINOSTUFFER_H
