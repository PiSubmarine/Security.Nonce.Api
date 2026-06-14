#include <gtest/gtest.h>

#include "PiSubmarine/Security/Nonce/Api/IProviderMock.h"

namespace PiSubmarine::Security::Nonce::Api
{
    TEST(NonceApiMockTest, ProviderMockCanReturnNonce)
    {
        IProviderMock provider;
        const Nonce expected{.Value = {std::byte{0x01}, std::byte{0x02}, std::byte{0x03}}};

        EXPECT_CALL(provider, Next())
            .WillOnce(testing::Return(Error::Api::Result<Nonce>(expected)));

        const auto result = provider.Next();

        ASSERT_TRUE(result.has_value());
        EXPECT_EQ(*result, expected);
    }
}
