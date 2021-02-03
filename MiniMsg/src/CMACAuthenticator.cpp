#include "CMACAuthenticator.h"
#include "DebugInterface.h"

namespace MiniMsg {
    CMACAuthenticator* CMACAuthenticator::s_instance;

    CMACAuthenticator::CMACAuthenticator()
    {

    }

    void CMACAuthenticator::create_instance()
    {
        static CMACAuthenticator c_instance;
        s_instance = &c_instance;
    }

    CMACAuthenticator& CMACAuthenticator::get_instance()
    {
        ASSERT(s_instance != nullptr, "tried to get NULL instance of CMACAuthenticator");
        return *s_instance;
    }

    void CMACAuthenticator::verify(bufferId_t bufferId, keyId_t keyId)
    {

    }

    void CMACAuthenticator::generate(bufferId_t bufferId)
    {

    }

    void CMACAuthenticator::add_hash(bufferId_t id)
    {
        
    }


};
