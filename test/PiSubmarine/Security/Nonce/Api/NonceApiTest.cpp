#include <gtest/gtest.h>

#include "PiSubmarine/Security/Nonce/Api/ErrorCode.h"
#include "PiSubmarine/Security/Nonce/Api/Nonce.h"

namespace PiSubmarine::Security::Nonce::Api
{
    TEST(NonceApiTest, NonceStoresOpaqueBytes)
    {
        const Nonce nonce{.Value = {std::byte{0xAA}, std::byte{0xBB}, std::byte{0xCC}}};

        ASSERT_EQ(nonce.Value.size(), 3U);
        EXPECT_EQ(nonce.Value[0], std::byte{0xAA});
        EXPECT_EQ(nonce.Value[1], std::byte{0xBB});
        EXPECT_EQ(nonce.Value[2], std::byte{0xCC});
    }

    TEST(NonceApiTest, ErrorCodeProducesExpectedMessage)
    {
        const auto errorCode = make_error_code(ErrorCode::NonceExhausted);

        EXPECT_EQ(errorCode.category().name(), std::string("PiSubmarine.Security.Nonce.Api"));
        EXPECT_EQ(errorCode.message(), std::string("nonce sequence is exhausted"));
    }
}
