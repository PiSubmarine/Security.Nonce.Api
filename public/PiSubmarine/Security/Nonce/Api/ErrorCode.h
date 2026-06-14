#pragma once

#include <system_error>

namespace PiSubmarine::Security::Nonce::Api
{
    enum class ErrorCode
    {
        InvalidConfiguration = 1,
        NonceExhausted
    };

    [[nodiscard]] std::error_code make_error_code(ErrorCode errorCode) noexcept;
}

namespace std
{
    template<>
    struct is_error_code_enum<PiSubmarine::Security::Nonce::Api::ErrorCode> : true_type
    {
    };
}
