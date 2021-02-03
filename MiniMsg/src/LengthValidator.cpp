#include "LengthValidator.h"
#include "DebugInterface.h"

namespace MiniMsg {
    LengthValidator* LengthValidator::s_instance;

    LengthValidator::LengthValidator()
    {

    }

    void LengthValidator::create_instance()
    {
        static LengthValidator c_instance;
        s_instance = &c_instance;
    }

    LengthValidator& LengthValidator::get_instance()
    {
        ASSERT(s_instance != nullptr, "tried to get NULL instance of LengthValidator");
        return *s_instance;
    }

    void LengthValidator::validate(bufferId_t bufferId)
    {
        
    }

    void LengthValidator::add_validator(bufferId_t bufferId)
    {

    }

    uint8_t LengthValidator::get_length_byte(bufferId_t bufferId)
    {

        return 0;
    }

    uint8_t LengthValidator::get_true_length(bufferId_t bufferId)
    {

        return 0;
    }

    void LengthValidator::set_length_byte(uint8_t length, bufferId_t bufferId)
    {

    }



};
