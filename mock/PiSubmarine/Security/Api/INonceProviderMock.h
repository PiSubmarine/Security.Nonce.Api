#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Security/Api/INonceProvider.h"

namespace PiSubmarine::Security::Api
{
    class INonceProviderMock : public INonceProvider
    {
    public:
        MOCK_METHOD((Error::Api::Result<Nonce>), Next, (), (override));
    };
}
