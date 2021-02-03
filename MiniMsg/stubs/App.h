#ifndef APP_H
#define APP_H

#include <MiniMsg.h>
#include <ApplicationInterface.h>

using namespace MiniMsg;

class App : public ApplicationInterface {
    public:
        App();
        void tick();
        void on_message(bufferId_t bufferId);
        messageId_t id();

    private:
        messageId_t m_msgId;
        uint32_t m_tickPeriod = DEFAULT_TICK;
};

#endif // APP_H