#ifndef TESTAPP_H
#define TESTAPP_H

#include <Arduino.h>
#include <MiniMsg.h>
#include <ApplicationInterface.h>

using namespace MiniMsg;

class Testapp : public ApplicationInterface {
    public:
        Testapp();
        void tick();
        void on_message(bufferId_t bufferId);
        messageId_t id();

    private:
        int m_level;
        messageId_t m_msgId;
};

#endif // TESTAPP_H
