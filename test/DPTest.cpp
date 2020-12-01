#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "DP.h"

using ::testing::_;
using ::testing::ElementsAre;

/* Maxprofit test cases:
   "" - 0
   "1" - 0
   "(1)" - 1
   
*/
TEST(DP, maxProfitTest)
{
    MaxProfit mp;

    EXPECT_EQ(mp.maxProfit({}),0);
    EXPECT_EQ(mp.maxProfit({1}),0);
    EXPECT_EQ(mp.maxProfit({3,2,-1}),0);
    EXPECT_EQ(mp.maxProfit({3,-1,-1}),0);
    EXPECT_EQ(mp.maxProfit({-1,2}),3);
    EXPECT_EQ(mp.maxProfit({7,2,5,1}),3);
    EXPECT_EQ(mp.maxProfit({7,-1,5,2,9}),10);
    EXPECT_EQ(mp.maxProfit({7,4,7,-1,5}),6);
}