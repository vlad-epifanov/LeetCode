#pragma once
#include "typedefs.h"

class UnionFind {
        std::vector<int> m_data;
    public:
        UnionFind(const size_t N);
        void unite(const int i, const int j);
        int find(const int node);
        int countGroups();
};

/*
1. Number of Provinces
https://leetcode.com/problems/number-of-provinces/

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

*/

class ProvincesCounter {
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected);
};

/*
2.
https://leetcode.com/problems/regions-cut-by-slashes/

*/

class SlashRegions {
public:
    int regionsBySlashes(std::vector<std::string>& grid);
private:
    UnionFind buildUF(std::vector<std::string>& grid);
};