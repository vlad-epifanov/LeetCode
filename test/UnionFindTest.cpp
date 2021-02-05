#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "UnionFind.h"



TEST(UnionFind, provincesTest)
{
    ProvincesCounter pc;

    EXPECT_EQ(pc.findCircleNum(Vec2D({{0}})), 1);
    EXPECT_EQ(pc.findCircleNum(Vec2D({{1}})), 1);
    EXPECT_EQ(pc.findCircleNum(Vec2D({{1,1},{1,1}})), 1);
    EXPECT_EQ(pc.findCircleNum(Vec2D({{0,0},{0,0}})), 2);
    EXPECT_EQ(pc.findCircleNum(Vec2D({{1,0},{0,1}})), 2);
    EXPECT_EQ(pc.findCircleNum(Vec2D({{1,1,0},{1,1,0},{0,0,1}})), 2);

    EXPECT_EQ(pc.findCircleNum(Vec2D(
       {{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
        {0,1,0,1,0,0,0,0,0,0,0,0,0,1,0},
        {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,0,1,0,0,0,1,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,1,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0,0,0,0,0,1,0,0},
        {0,1,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}})), 8);

    EXPECT_EQ(pc.findCircleNum(Vec2D({{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}})), 1);

    EXPECT_EQ(pc.findCircleNum(Vec2D(
        { {1,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
          {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
          {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
          {0,0,0,1,0,1,1,0,0,0,0,0,0,0,0},
          {0,0,0,0,1,0,0,0,0,1,1,0,0,0,0},
          {0,0,0,1,0,1,0,0,0,0,1,0,0,0,0},
          {0,0,0,1,0,0,1,0,1,0,0,0,0,1,0},
          {1,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
          {0,0,0,0,0,0,1,1,1,0,0,0,0,1,0},
          {0,0,0,0,1,0,0,0,0,1,0,1,0,0,1},
          {0,0,0,0,1,1,0,0,0,0,1,1,0,0,0},
          {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},
          {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
          {0,0,0,0,0,0,1,0,1,0,0,0,0,1,0},
          {0,0,0,0,0,0,0,0,0,1,0,0,0,0,1}})),3);

}

TEST(UnionFind, regionsBySlashesTest)
{
    using Grid = vector<string>;
    SlashRegions sr;
    EXPECT_EQ(sr.regionsBySlashes(Grid({" "})), 1);
    EXPECT_EQ(sr.regionsBySlashes(Grid({"\\"})), 2);
    EXPECT_EQ(sr.regionsBySlashes(Grid({"/"})), 2);
    EXPECT_EQ(sr.regionsBySlashes(Grid{" "}), 1);
    EXPECT_EQ(sr.regionsBySlashes(Grid{" /",
                                       "/ " }), 2);
    EXPECT_EQ(sr.regionsBySlashes(Grid{" /",
                                       "  " }), 1);
    EXPECT_EQ(sr.regionsBySlashes(Grid{"\\/",
                                       "/\\" }), 4);

    EXPECT_EQ(sr.regionsBySlashes(Grid{"    ",
                                       " /\\ ",
                                       " \\/ ",
                                       "    " }), 2);
}