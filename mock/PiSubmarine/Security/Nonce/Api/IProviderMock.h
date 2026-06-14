#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Security/Nonce/Api/IProvider.h"

namespace PiSubmarine::Security::Nonce::Api
{
    class IProviderMock : public IProvider
    {
    public:
        MOCK_METHOD((Error::Api::Result<Nonce>), Next, (), (override));
    };
}
