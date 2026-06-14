#pragma once

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Security/Api/Nonce.h"

namespace PiSubmarine::Security::Api
{
    class INonceProvider
    {
    public:
        virtual ~INonceProvider() = default;

        [[nodiscard]] virtual Error::Api::Result<Nonce> Next() = 0;
    };
}
