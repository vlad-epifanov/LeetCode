#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "DFS.h"

using ::testing::_;
using ::testing::ElementsAre;

/* DFS test cases:
   
*/
TEST(DFS, allPathsTest)
{
    AllGraphPaths agp;
    
    EXPECT_TRUE(agp.allPathsSourceTarget(Graph()).empty());

    auto res = agp.allPathsSourceTarget(Graph({{1},{}}));
    EXPECT_THAT(res, ElementsAre(std::vector<int>({0,1})));
    
    res = agp.allPathsSourceTarget(Graph({{1,2},{3},{3},{}}));
    EXPECT_THAT(res, ElementsAre(std::vector<int>({0,1,3}),std::vector<int>({0,2,3})));

    res = agp.allPathsSourceTarget(Graph({{1,2},{3},{3},{},{}}));
    EXPECT_TRUE(res.empty());

    res = agp.allPathsSourceTarget(Graph({{1,2},{3},{4},{},{}}));
    EXPECT_THAT(res, ElementsAre(std::vector<int>({0,2,4})));

}

TEST(DFS, longestIncrPathTest)
{
    LongestIncrPath lip;
    EXPECT_EQ(lip.longestIncreasingPath(Graph()), 0);
    EXPECT_EQ(lip.longestIncreasingPath(Graph({{1}})), 1);
    EXPECT_EQ(lip.longestIncreasingPath(Graph({{0}})), 1);
    EXPECT_EQ(lip.longestIncreasingPath(Graph({{0,2,0}})), 2);
    EXPECT_EQ(lip.longestIncreasingPath(Graph({{3,2,1}})), 3);
    EXPECT_EQ(lip.longestIncreasingPath(Graph({{3},{2},{1}})), 3);
    EXPECT_EQ(lip.longestIncreasingPath(Graph({{1},{2},{1}})), 2);
    EXPECT_EQ(lip.longestIncreasingPath(Graph({{1,2,3},{4,5,6},{7,8,9}})), 5);

}

TEST(DFS, roomsAndKeysTest)
{
    RoomsAndKeys rak;

    EXPECT_TRUE(rak.canVisitAllRooms(Vec2D({{1},{2},{}})));
    EXPECT_FALSE(rak.canVisitAllRooms(Vec2D({{1},{2},{1},{3}})));
    EXPECT_TRUE(rak.canVisitAllRooms(Vec2D({{2,3},{3},{1},{1,2}})));
    EXPECT_FALSE(rak.canVisitAllRooms(Vec2D({{},{3},{1},{1,2}})));
}

TEST(DFS, maxAreaIslandTest)
{
    MaxAreaIsland mai;

    EXPECT_EQ(mai.maxAreaOfIsland(Vec2D({{}})), 0);
    EXPECT_EQ(mai.maxAreaOfIsland(Vec2D({{0}})), 0);
    EXPECT_EQ(mai.maxAreaOfIsland(Vec2D({{1}})), 1);
    EXPECT_EQ(mai.maxAreaOfIsland(Vec2D({{0,1,1,0,1,0}})), 2);

    EXPECT_EQ(mai.maxAreaOfIsland(Vec2D({{1,0},{0,1}})), 1);
    EXPECT_EQ(mai.maxAreaOfIsland(Vec2D({{1,0},{1,1}})), 3);

    EXPECT_EQ(mai.maxAreaOfIsland(Vec2D({{1,0,0},{0,1,1},{0,1,1}})), 4);
}

TEST(DFS, jumpGameTest)
{
    JumpGame jm;

    EXPECT_TRUE(jm.canReach(Vec({0}),0));
    EXPECT_TRUE(jm.canReach(Vec({1,0}),0));
    EXPECT_TRUE(jm.canReach(Vec({1,0}),1));
    EXPECT_TRUE(jm.canReach(Vec({0,1,0}),1));
    EXPECT_TRUE(jm.canReach(Vec({0,1,0,2}),3));
    EXPECT_FALSE(jm.canReach(Vec({6,1,5,2}),3));
    EXPECT_TRUE(jm.canReach(Vec({4,2,3,0,3,1,2}),0));
}