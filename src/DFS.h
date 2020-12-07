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
    vector<int> m_curPath;
    void findPathFromNode(const int curNode, const Graph& graph);
public:
    vector<vector<int>> allPathsSourceTarget(Graph& graph);
};