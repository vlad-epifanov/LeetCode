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

/* Depth test cases:
   "" - 0
   "1" - 0
   "(1)" - 1
   
*/
TEST(Strings, nestingDepth) {
    NestingDepth dCalc;

    EXPECT_EQ(dCalc.maxDepth(""),0);
    EXPECT_EQ(dCalc.maxDepth("1"),0);
    EXPECT_EQ(dCalc.maxDepth("(1)"),1);
    EXPECT_EQ(dCalc.maxDepth("(1)+(1)"),1);
    EXPECT_EQ(dCalc.maxDepth("((1))"),2);
    EXPECT_EQ(dCalc.maxDepth("((1)*(1))"),2);
    EXPECT_EQ(dCalc.maxDepth("((1+2)+(1*3)+(1+(2+2)))"),3);
}

TEST(Strings, flipper) {
    BulbSwitcher flipper;

    EXPECT_EQ(flipper.minFlips(""),0);
    EXPECT_EQ(flipper.minFlips("0"),0);
    EXPECT_EQ(flipper.minFlips("1"),1);
    EXPECT_EQ(flipper.minFlips("00"),0);
    EXPECT_EQ(flipper.minFlips("001"),1);
    EXPECT_EQ(flipper.minFlips("101"),3);
    EXPECT_EQ(flipper.minFlips("10101"),5);

}


