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
