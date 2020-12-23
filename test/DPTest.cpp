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

TEST(DP, MXBlockSumTest)
{
    MXBlockSum mbs;
    auto res = mbs.matrixBlockSum(Vec2D({{1}}),1);
    EXPECT_EQ(res,Vec2D({{1}}));
    res = mbs.matrixBlockSum(Vec2D({{1,3}}),1);
    EXPECT_EQ(res,Vec2D({{4,4}}));
    res = mbs.matrixBlockSum(Vec2D({{1},{3}}),1);
    EXPECT_EQ(res,Vec2D({{4},{4}}));
    res = mbs.matrixBlockSum(Vec2D({{1,2},{3,4}}),1);
    EXPECT_EQ(res,Vec2D({{10,10},{10,10}}));
    res = mbs.matrixBlockSum(Vec2D({{1,2,3},{4,5,6},{7,8,9}}),1);
    EXPECT_EQ(res,Vec2D({{12,21,16},{27,45,33},{24,39,28}}));
}

TEST(DP, CountBitSet)
{
    CountBits cb;

    auto res = cb.countBits(2);
    EXPECT_EQ(res,Vec({0,1,1}));
    res = cb.countBits(0);
    EXPECT_EQ(res,Vec({0}));
    res = cb.countBits(1);
    EXPECT_EQ(res,Vec({0,1}));
    res = cb.countBits(5);
    EXPECT_EQ(res,Vec({0,1,1,2,1,2}));
    res = cb.countBits(8);
    EXPECT_EQ(res,Vec({0,1,1,2,1,2,2,3,1}));
}

TEST(DP, CountSortedVowelsTest)
{
    CountSortedVowels cvs;

    EXPECT_EQ(cvs.countVowelStrings(0),0);
    EXPECT_EQ(cvs.countVowelStrings(1),5);
    EXPECT_EQ(cvs.countVowelStrings(2),15);
    EXPECT_EQ(cvs.countVowelStrings(3),35);
    EXPECT_EQ(cvs.countVowelStrings(33),66045);
}

TEST(DP, BinaryMatrixTest)
{
    SquareCounter sc;

    EXPECT_EQ(sc.countSquares(Vec2D({{0}})),0);
    EXPECT_EQ(sc.countSquares(Vec2D({{1}})),1);
    EXPECT_EQ(sc.countSquares(Vec2D({{0,1}})),1);
    EXPECT_EQ(sc.countSquares(Vec2D({{0,1},{1,0}})),2);
    EXPECT_EQ(sc.countSquares(Vec2D({{1,1},{1,1}})),5);
    EXPECT_EQ(sc.countSquares(Vec2D({{1,0},{1,1},{1,1}})),6);
    EXPECT_EQ(sc.countSquares(Vec2D({{1,0,1},{1,1,1},{1,1,1}})),10);
}

TEST(DP, BinaryMatrixTest2)
{
    SquareCounterLoop sc;

    EXPECT_EQ(sc.countSquares(Vec2D({{0}})),0);
    EXPECT_EQ(sc.countSquares(Vec2D({{1}})),1);
    EXPECT_EQ(sc.countSquares(Vec2D({{0,1}})),1);
    EXPECT_EQ(sc.countSquares(Vec2D({{0,1},{1,0}})),2);
    EXPECT_EQ(sc.countSquares(Vec2D({{1,1},{1,1}})),5);
    EXPECT_EQ(sc.countSquares(Vec2D({{1,0},{1,1},{1,1}})),6);
    EXPECT_EQ(sc.countSquares(Vec2D({{1,0,1},{1,1,1},{1,1,1}})),10);
}

TEST(DP, BinaryMatrixTest3)
{
    SquareCounterLoop2 sc;

    EXPECT_EQ(sc.countSquares(Vec2D({{0}})),0);
    EXPECT_EQ(sc.countSquares(Vec2D({{1}})),1);
    EXPECT_EQ(sc.countSquares(Vec2D({{0,1}})),1);
    EXPECT_EQ(sc.countSquares(Vec2D({{0,1},{1,0}})),2);
    EXPECT_EQ(sc.countSquares(Vec2D({{1,1},{1,1}})),5);
    EXPECT_EQ(sc.countSquares(Vec2D({{1,0},{1,1},{1,1}})),6);
    EXPECT_EQ(sc.countSquares(Vec2D({{1,0,1},{1,1,1},{1,1,1}})),10);
}
