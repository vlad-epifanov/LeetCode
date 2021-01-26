#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Bits.h"

TEST(Bits, SNTest)
{
    SingleNumber sn;
    EXPECT_EQ(sn.singleNumber(Vec({0})), 0);
    EXPECT_EQ(sn.singleNumber(Vec({0,1,0,0})), 1);
    EXPECT_EQ(sn.singleNumber(Vec({0,1,0,1,0,1,2})), 2);
    EXPECT_EQ(sn.singleNumber(Vec({0,1,0,1,0,1,99})), 99);
    EXPECT_EQ(sn.singleNumber(Vec({2,2,2,-1,-1,-1,8,-7,0,-7,0,-7,0})),8);
}

