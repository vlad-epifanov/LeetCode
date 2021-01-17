#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Arrays/Median.h"

using ::testing::_;
using ::testing::ElementsAre;

TEST(Medians, testSlidingMedian)
{
    SlidingMedian sm;

    vector<double> res = sm.medianSlidingWindow(Vec({1}),1);
    EXPECT_EQ(res,vector<double>({1}));

    res = sm.medianSlidingWindow(Vec({-1,2,3}),3);
    EXPECT_EQ(res,vector<double>({2}));

    res = sm.medianSlidingWindow(Vec({-1,0,3,4}),4);
    EXPECT_EQ(res,vector<double>({1.5}));

    res = sm.medianSlidingWindow(Vec({-1,0,3,4}),1);
    EXPECT_EQ(res,vector<double>({-1,0,3,4}));

    res = sm.medianSlidingWindow(Vec({1,3,-1,-3,5,3,6,7}),3);
    EXPECT_EQ(res,vector<double>({1,-1,-1,3,5,6}));

    res = sm.medianSlidingWindow(Vec({2147483647,2147483647}),2);
    EXPECT_EQ(res,vector<double>({2147483647}));

}
