#include "PiSubmarine/Security/Nonce/Api/ErrorCode.h"

namespace PiSubmarine::Security::Nonce::Api
{
    namespace
    {
        class ErrorCategory final : public std::error_category
        {
        public:
            [[nodiscard]] const char* name() const noexcept override
            {
                return "PiSubmarine.Security.Nonce.Api";
            }

            [[nodiscard]] std::string message(const int condition) const override
            {
                switch (static_cast<ErrorCode>(condition))
                {
                case ErrorCode::InvalidConfiguration:
                    return "nonce provider configuration is invalid";
                case ErrorCode::NonceExhausted:
                    return "nonce sequence is exhausted";
                }

                return "unknown nonce error";
            }
        };
    }

    std::error_code make_error_code(const ErrorCode errorCode) noexcept
    {
        static const ErrorCategory Category;
        return {static_cast<int>(errorCode), Category};
    }
}
