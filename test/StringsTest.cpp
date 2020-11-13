#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "StringsBasic.h"

using ::testing::_;
using ::testing::ElementsAre;

/* Defang test cases:
   0.0.0.0
   123.1.123.1
   5.21.5.123
*/
TEST(Strings, test1) {
    IP4Defang defanger;

    auto result = defanger.defangIPaddr("0.0.0.0");
    EXPECT_EQ(result, "0[.]0[.]0[.]0");

    result = defanger.defangIPaddr("123.1.123.1");
    EXPECT_EQ(result, "123[.]1[.]123[.]1");

    result = defanger.defangIPaddr("5.21.5.123");
    EXPECT_EQ(result, "5[.]21[.]5[.]123");

}
