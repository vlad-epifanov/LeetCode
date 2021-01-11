#pragma once
#include "typedefs.h"

// used only for quick copy-paste to LeetCode - avoid in production!
using namespace std;

/*
1. All Paths From Source to Target
https://leetcode.com/problems/all-paths-from-source-to-target/

Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1, 
and return them in any order.
The graph is given as follows: graph[i] is a list of all nodes you can visit from node i 
(i.e., there is a directed edge from node i to node graph[i][j]).

n == graph.length
2 <= n <= 15
0 <= graph[i][j] < n

Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
*/

class EXPORT_SYM AllGraphPaths
{
    int m_lastNode;
    vector<vector<int>> m_graphPaths;
    void findPathFromNode(const int curNode, const Graph& graph, vector<int>& curPath);
public:
    vector<vector<int>> allPathsSourceTarget(Graph& graph);
};

/*
2. Longest Increasing Path in a Matrix

https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

Given an m x n matrix, return the length of the longest increasing path in matrix.
From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

Example 1:

Input: matrix = [[9,9,4],
                 [6,6,8],
                 [2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
*/

class LongestIncrPath {
    int getLongestPath(const int prevVal, const int i, const int j, const Vec2D& matrix);
    Vec2D mpCache_;
public:
    int longestIncreasingPath(Vec2D& matrix);
};
