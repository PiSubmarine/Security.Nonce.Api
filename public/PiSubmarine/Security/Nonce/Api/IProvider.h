#pragma once

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Security/Nonce/Api/Nonce.h"

namespace PiSubmarine::Security::Nonce::Api
{
    class IProvider
    {
    public:
        virtual ~IProvider() = default;

        [[nodiscard]] virtual Error::Api::Result<Nonce> Next() = 0;
    };
}
