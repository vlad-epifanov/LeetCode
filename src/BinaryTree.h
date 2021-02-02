
#pragma once
#include "typedefs.h"

// Used only for quick copy-paste to LeetCode - avoid in production!
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void releaseTree(TreeNode* tree);

/**
 * Binary tree serialization tools
 */

class TreeSerializer
{
    public:
        vector<int> serializeTree(TreeNode *root, size_t treeSize);
        TreeNode* deserializeTree(const vector<int>& tree);
    private:
        void serializeSubTree(TreeNode *root, int startIdx = 0);
        TreeNode* deserializeSubTree(const vector<int>& tree, int startIdx = 0);
    private:
        vector<int> m_serializedTree;
};

/***************************************
1)  Flip Equivalent Binary Trees
https://leetcode.com/problems/flip-equivalent-binary-trees/
Given the roots of two binary trees root1 and root2, return true if the two trees are flip equivelent or false otherwise.
*/

class FlipChecker {
    bool flipEquivSubtree(TreeNode* root1, TreeNode* root2);
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2);
};

/***************************************
2. Maximum Level Sum of a Binary Tree
https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
*/

class MaxLevelSum {
public:
    int maxLevelSum(TreeNode* root);
};