#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "LineSweep.h"

using ::testing::_;
using ::testing::ElementsAre;

TEST(LineSweepTests, skyLineTest)
{
    SkyLine sl;

    Vec2D result = sl.getSkyline(Vec2D{{{0,1,1}}});
    EXPECT_EQ(result, Vec2D({{0,1},{1,0}}));

    result = sl.getSkyline(Vec2D{{{0,1,1},{1,3,2},{4,5,1}}});
    EXPECT_EQ(result, Vec2D({{0,1},{1,2},{3,0},{4,1},{5,0}}));

    result = sl.getSkyline(Vec2D{{{0,1,1},{0,3,4},{2,5,1}}});
    EXPECT_EQ(result, Vec2D({{0,4},{3,1},{5,0}}));

    result = sl.getSkyline(Vec2D({{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}}));
    EXPECT_EQ(result, Vec2D({{2,10},{3,15},{7,12},{12,0},{15,10},{20,8},{24,0}}));

    result = sl.getSkyline(Vec2D({{0,3,3},{1,5,3},{2,4,3},{3,7,3}}));
    EXPECT_EQ(result, Vec2D({{0,3},{7,0}}));
}