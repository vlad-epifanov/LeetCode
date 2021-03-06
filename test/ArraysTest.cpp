#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Arrays/ArraysBasic.h"

using ::testing::_;
using ::testing::ElementsAre;

/* RunningSum test cases:
   1
   1 2 3
   -2 3 -5
*/
TEST(Arrays, test1) {
    RunningSum rsum;

    auto result = rsum.runningSum({1});
    EXPECT_THAT(result, ElementsAre(1));

    result = rsum.runningSum({1,2,3});
    EXPECT_THAT(result, ElementsAre(1,3,6));

    result = rsum.runningSum({1,-2,3});
    EXPECT_THAT(result, ElementsAre(1,-1,2));
}

/*
Test cases:
    1) Corner cases: empty rectangle, out-of-bounds accesses, inconsistent vectors
    2) Inconsistent input arguments (like Col1 > Col2 etc)
    2) 1x1
    3) 3x3
        3.1) Entire rectangle
        3.2) Entire rows
        3.3) 2,2 - 3,3
*/

TEST(Arrays, testQuery) {
    std::vector<std::vector<int>> vector = {{1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}};
    SubrectangleQueries query(vector);

    query.updateSubrectangle(0,0,3,2,5);
    auto result = query.getValue(0,2);
    EXPECT_EQ(result, 5);

    result = query.getValue(3,1);
    EXPECT_EQ(result, 5);
}

TEST(Arrays, testMostWater)
{
    MostWater mwCalc;

    EXPECT_EQ(mwCalc.maxArea(Vec({1})), 0);
    EXPECT_EQ(mwCalc.maxArea(Vec({1,1})), 1);
    EXPECT_EQ(mwCalc.maxArea(Vec({1,2,1,3})), 4);
    EXPECT_EQ(mwCalc.maxArea(Vec({2,4,3})), 4);
    EXPECT_EQ(mwCalc.maxArea(Vec({1,1,1})), 2);
    EXPECT_EQ(mwCalc.maxArea(Vec({1,3,3,2,1,1})), 5);
}

TEST(Arrays, testMatrixTranspose)
{
    TransposeMatrix tx;

    Vec2D res = tx.transpose(Vec2D({{1}}));
    EXPECT_EQ(res,Vec2D({{1}}));
    res = tx.transpose(Vec2D({{1,2}}));
    EXPECT_EQ(res,Vec2D({{1},{2}}));
    res = tx.transpose(Vec2D({{1},{2}}));
    EXPECT_EQ(res,Vec2D({{1,2}}));
    res = tx.transpose(Vec2D({{1,2},{3,4}}));
    EXPECT_EQ(res,Vec2D({{1,3},{2,4}}));
}

TEST(Arrays, testMatrixSpiral)
{
    SpiralMatrix smx;

    Vec res = smx.spiralOrder(Vec2D({{1}}));
    EXPECT_EQ(res,Vec({1}));
    res = smx.spiralOrder(Vec2D({{1,2}}));
    EXPECT_EQ(res,Vec({1,2}));
    res = smx.spiralOrder(Vec2D({{1},{2}}));
    EXPECT_EQ(res,Vec({1,2}));
    res = smx.spiralOrder(Vec2D({{1,2,3}}));
    EXPECT_EQ(res,Vec({1,2,3}));
    res = smx.spiralOrder(Vec2D({{1},{2},{3}}));
    EXPECT_EQ(res,Vec({1,2,3}));
    res = smx.spiralOrder(Vec2D({{1,2},{3,4}}));
    EXPECT_EQ(res,Vec({1,2,4,3}));

    res = smx.spiralOrder(Vec2D({{1,2,3},{4,5,6},{7,8,9}}));
    EXPECT_EQ(res,Vec({1,2,3,6,9,8,7,4,5}));
}
