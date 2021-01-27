#pragma once
#include "typedefs.h"
#include <queue>

// used only for quick copy-paste to LeetCode - avoid in production!
using namespace std;


/************************************************/
/*
1. Level-order traversal
https://leetcode.com/problems/n-ary-tree-level-order-traversal/submissions/
*/

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, const vector<Node*>& _children) {
        val = _val;
        children = _children;
    }
};

class LevelOrder {
public:
    vector<vector<int>> levelOrder(Node* root);
};

/************************************************/