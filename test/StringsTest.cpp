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

TEST(Strings, validBracketsTest) {

    BalanceChecker checker;

    EXPECT_FALSE(checker.isValid(string("(")));
    EXPECT_FALSE(checker.isValid(string("(((")));
    EXPECT_FALSE(checker.isValid(string(")(((")));
    EXPECT_TRUE(checker.isValid(string("()()")));
    EXPECT_TRUE(checker.isValid(string("(){}()")));
    EXPECT_FALSE(checker.isValid(string("([{}()]")));
    EXPECT_FALSE(checker.isValid(string("(]")));
    EXPECT_FALSE(checker.isValid(string("([)]")));
    EXPECT_TRUE(checker.isValid(string("{[]}")));
}

TEST(Strings, MinStepToAnagramTest) {

    MinStepToAnagram stepCounter;

    EXPECT_EQ(stepCounter.minSteps(string("a"), string("a")),0);
    EXPECT_EQ(stepCounter.minSteps(string("a"), string("b")),1);
    EXPECT_EQ(stepCounter.minSteps(string("abc"), string("baa")),1);
    EXPECT_EQ(stepCounter.minSteps(string("abc"), string("def")),3);
    EXPECT_EQ(stepCounter.minSteps(string("abc"), string("cab")),0);
}

TEST(Strings, StrSwapTest)
{
    StrSwap swapper;
    EXPECT_EQ(swapper.minimumSwap(string("x"), string("y")),-1);
    EXPECT_EQ(swapper.minimumSwap(string("xy"), string("yx")),2);
    EXPECT_EQ(swapper.minimumSwap(string("x"), string("x")),0);
    EXPECT_EQ(swapper.minimumSwap(string("xx"), string("yy")),1);
    EXPECT_EQ(swapper.minimumSwap(string("xx"), string("yx")),-1);
    EXPECT_EQ(swapper.minimumSwap(string("xxyy"), string("yyxx")),2);
    EXPECT_EQ(swapper.minimumSwap(string("xxxyyy"), string("yyyxxx")),4);
    EXPECT_EQ(swapper.minimumSwap(string("xxyyxyxyxx"), string("xyyxyxxxyx")),4);

}