#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Trees/BinaryTree.h"

using TreePtr = std::unique_ptr<TreeNode, decltype(&releaseTree)>;

TEST(BinaryTree, flipEqTest)
{
    FlipChecker fc;
    
    TreeSerializer ts;
    TreeNode* root1 = ts.deserializeTree(Vec({}));
    TreeNode* root2 = root1;
    
    EXPECT_TRUE(fc.flipEquiv(root1, root2));
    
    root1 = ts.deserializeTree(Vec({1}));
    root2 = ts.deserializeTree(Vec({1}));
    EXPECT_TRUE(fc.flipEquiv(root1, root2));
    releaseTree(root1);
    releaseTree(root2);

    root1 = ts.deserializeTree(Vec({1}));
    root2 = ts.deserializeTree(Vec({2}));
    EXPECT_FALSE(fc.flipEquiv(root1, root2));
    releaseTree(root1);
    releaseTree(root2);

    root1 = ts.deserializeTree(Vec({1,2,3}));
    root2 = ts.deserializeTree(Vec({1,3,2}));
    EXPECT_TRUE(fc.flipEquiv(root1, root2));
    releaseTree(root1);
    releaseTree(root2);

    root1 = ts.deserializeTree(Vec({1,4,3}));
    root2 = ts.deserializeTree(Vec({1,3,2}));
    EXPECT_FALSE(fc.flipEquiv(root1, root2));
    releaseTree(root1);
    releaseTree(root2);

    root1 = ts.deserializeTree(Vec({1,2,INT_MAX,3,4}));
    root2 = ts.deserializeTree(Vec({1,INT_MAX,2,INT_MAX,INT_MAX,3,4}));
    EXPECT_TRUE(fc.flipEquiv(root1, root2));
    releaseTree(root1);
    releaseTree(root2);

}

TEST(BinaryTree, maxLevelSumTest)
{
    MaxLevelSum mls;
    TreeSerializer ts;

    TreePtr root1(ts.deserializeTree(Vec({})), &releaseTree);
    EXPECT_EQ(mls.maxLevelSum(root1.get()),0);

    root1 = TreePtr(ts.deserializeTree(Vec({1})), &releaseTree);
    EXPECT_EQ(mls.maxLevelSum(root1.get()),1);

    root1 = TreePtr(ts.deserializeTree(Vec({-10})), &releaseTree);
    EXPECT_EQ(mls.maxLevelSum(root1.get()),1);

    root1 = TreePtr(ts.deserializeTree(Vec({1,2,3})), &releaseTree);
    EXPECT_EQ(mls.maxLevelSum(root1.get()),2);

    root1 = TreePtr(ts.deserializeTree(Vec({1,2,-3})), &releaseTree);
    EXPECT_EQ(mls.maxLevelSum(root1.get()),1);

    root1 = TreePtr(ts.deserializeTree(Vec({1,10,10,-5,6,INT_MAX,10})), &releaseTree);
    EXPECT_EQ(mls.maxLevelSum(root1.get()),2);

    root1 = TreePtr(ts.deserializeTree(Vec({1,-10,10,-5,6,INT_MAX,10})), &releaseTree);
    EXPECT_EQ(mls.maxLevelSum(root1.get()),3);

}
