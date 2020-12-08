#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Greedy.h"

using ::testing::_;
using ::testing::ElementsAre;

/* SplitBalancedString test cases:
   empty
   L, R
   LR, RL - 1
   LRRLLRLR - 4
   LLRR - 1
   LLLRRR - 1
   LRLLRRLLRRLR - 4
   RLRRRLLRLL - 2
*/
TEST(Greedy, balanceString)
{
    SplitBalancedString sbs;

    EXPECT_EQ(sbs.balancedStringSplit(""), 0);
    EXPECT_EQ(sbs.balancedStringSplit("L"), 0);
    EXPECT_EQ(sbs.balancedStringSplit("R"), 0);
    EXPECT_EQ(sbs.balancedStringSplit("RL"), 1);
    EXPECT_EQ(sbs.balancedStringSplit("LR"), 1);
    EXPECT_EQ(sbs.balancedStringSplit("LRRLLRLR"), 4);
    EXPECT_EQ(sbs.balancedStringSplit("LLRR"), 1);
    EXPECT_EQ(sbs.balancedStringSplit("LLLRRR"), 1);
    EXPECT_EQ(sbs.balancedStringSplit("LRLLRRLLRRLR"), 4);
    EXPECT_EQ(sbs.balancedStringSplit("RLRRRLLRLL"), 2);
}

/* PeopleGrouper test cases:
   empty - {}
   {1} - {{0}}
   {1,1} - {{0},{1}}
   {2,1,2} - {{1},{0,2}}
   {3,3,3} - {{0,1,2}}
   {3,1,2,3,2,3} - {{1},{2,4},{0,3,5}}
*/
TEST(Greedy, pGrouper)
{
    PeopleGrouper pg;

    auto result = pg.groupThePeople({});
    EXPECT_TRUE(result.empty());

    result = pg.groupThePeople({1});
    EXPECT_EQ(result, Vec2D({{0}}));
    
    result = pg.groupThePeople({1,1});
    EXPECT_EQ(result, Vec2D({{0},{1}}));

    result = pg.groupThePeople({2,1,2});
    EXPECT_EQ(result, Vec2D({{1},{0,2}}));

    result = pg.groupThePeople({3,3,3});
    EXPECT_EQ(result, Vec2D({{0,1,2}}));

    result = pg.groupThePeople({3,1,2,3,2,3});
    EXPECT_EQ(result, Vec2D({{1},{2,4},{0,3,5}}));
}