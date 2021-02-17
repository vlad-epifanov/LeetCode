#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "LRUCache.h"

TEST(KRUCacheTests, cacheTest)
{
    LRUCache lc1(0);

    lc1.put(1,2);
    EXPECT_EQ(lc1.get(1),-1);

    LRUCache lc2(1);
    EXPECT_EQ(lc2.get(1),-1);
    lc2.put(1,2);
    EXPECT_EQ(lc2.get(1),2);
    lc2.put(2,3);
    EXPECT_EQ(lc2.get(1),-1);
    EXPECT_EQ(lc2.get(2),3);

    LRUCache lc3(2);
    lc3.put(1,2);
    lc3.put(2,3);
    EXPECT_EQ(lc3.get(1),2);
    EXPECT_EQ(lc3.get(2),3);
    lc3.put(3,4);
    EXPECT_EQ(lc3.get(1),-1);
    EXPECT_EQ(lc3.get(2),3);
    lc3.put(5,6);
    EXPECT_EQ(lc3.get(3),-1);
    lc3.put(2,7);
    EXPECT_EQ(lc3.get(5),6);
    EXPECT_EQ(lc3.get(2),7);
}